template<class T=int>
struct SegTree {
	int n; vector<T> tree;
	T un; function<T(T, T)> op;
	SegTree(
			int size, T unit=INT_MIN, 
			function<T(T, T)> oper=[](T a, T b)->T { return max(a, b); }
			) : n(size), tree(2*n, unit), un(unit), op(oper) { }
	void set(int i, T v) {
		i += n; tree[i] = v;
		do { i /= 2; tree[i] = op(tree[2*i], tree[2*i+1]); }
		while(i);
	}
	T operator[](int i) { return tree[n+i]; }
	T operator()(int a, int b) {
		T l = un, r = un;
		for(a += n, b += n; a < b; a /= 2, b /= 2) {
			if(a % 2 == 1) l = op(l, tree[a++]);
			if(b % 2 == 1) r = op(tree[--b], r);
		}
		return op(l, r);
	}
};
