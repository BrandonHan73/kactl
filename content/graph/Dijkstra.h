/**
 * Author: Brandon Han
 * Date: 2025-09-18
 * License: ???
 * Source: https://en.wikipedia.org/wiki/Dijkstra's_algorithm
 * Description: Computes shortest paths from source vertices to
 * all other vertices in a weighted directed graph. Input array should be
 * starting distances of each node, e.g. input[source] = 0 and
 * input[not source] = inf. Unreachable nodes get dist = inf
 * Usage: 
 * Dijkstra dij(n);  dij.addEdge(a, b, w);
 * vector<ll> dist(n, inf);  dist[source] = 0;
 * dij.solve(dist);
 */
#pragma once

const ll inf = LLONG_MAX;
struct Dijkstra {
	typedef pair<ll, int> plli;
	vector<vector<plli>> eds;
	Dijkstra(int n) : eds(n) {}
	void addEdge(int a, int b, ll w=1) {
		eds[a].push_back({w, b});
	}
	void solve(vector<ll> &out) {
		priority_queue<plli, vector<plli>, greater<plli>> pq;
		rep(i, 0, sz(out)) pq.push({out[i], i});
		fill(all(out), inf);
		while(sz(pq) > 0) {
			plli dc = pq.top(); pq.pop();
			if(dc.first >= out[dc.second]) continue;
			out[dc.second] = dc.first;
			for(plli e : eds[dc.second]) pq.push({dc.first + e.first, e.second});
		}
	}
};

