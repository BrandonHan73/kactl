/**
 * Author: Brandon Han
 * Date: 2025-09-18
 * License: ???
 * Source: https://en.wikipedia.org/wiki/Dijkstra's_algorithm
 * Description: Computes shortest paths from source vertices to
 * vertices in a weighted directed graph. Given the input array, 
 * assumes you can jump to node n instantly with distance input[n]. 
 * Unreachable nodes get dist = inf
 * Usage: 
 * Dijkstra dij(n);  dij.addEdge(a, b, w);
 * vector<ll> dist(n, inf);  dist[source] = 0;
 * dij.solve(dist);
 */
#pragma once

const ll inf = LLONG_MAX;
struct Dijkstra {
	typedef pair<ll, int> plli;
	vector<vector<plli>> edges;
	Dijkstra(int n) : edges(n) {}
	void addEdge(int a, int b, ll w=1) {
		edges[a].push_back({w, b});
	}
	void solve(vector<ll> &out) {
		priority_queue<plli, vector<plli>, greater<plli>> pq;
		rep(i, 0, sz(out)) pq.push({ out[i], i });
		fill(all(out), inf);
		while(sz(pq) > 0) {
			plli dc = pq.top();
			pq.pop();
			if(dc.first >= out[dc.second]) continue;
			out[dc.second] = dc.first;
			for(plli edge : edges[dc.second]) pq.push({dc.first + edge.first, edge.second});
		}
	}
};

