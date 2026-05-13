/**
 * Author: Brandon Han
 * Date: 2025-10-05
 * License: ???
 * Source: ???
 * Description: Operators for fraction arithmetic. Will likely
 * break down after a few operations due to overflow. 
 */
#pragma once

const ll MOD = 1e9 + 7;
ll euclid(ll a, ll b, ll &x, ll &y) {
	if(!b) return x=1, y=0, a;
	ll d = euclid(b, a%b, y, x);
	return y -= a/b * x, d;
}
struct Mod {
	ll x;
	Mod(ll xx=0) : x(xx % MOD) {
		if(xx < 0) x = xx + (-xx / MOD + 1) * MOD;
	}
	Mod operator+(Mod b) { return Mod(x + b.x); }
	Mod operator-(Mod b) { return *this + b.negate(); }
	Mod operator*(Mod b) { return Mod(x * b.x); }
	Mod operator/(Mod b) { return *this * b.invert(); }
	Mod negate() { return Mod(MOD - x); }
	Mod invert() {
		ll a, b, g = euclid(x, MOD, a, b);
		assert(g == 1);
		return Mod(a);
	}
	friend ostream &operator<<(ostream &st, Mod a) { return st << a.x; }
};
typedef vector<Mod> vm;
