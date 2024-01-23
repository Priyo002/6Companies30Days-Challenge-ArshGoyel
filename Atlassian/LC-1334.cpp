#include<bits/stdc++.h>
using namespace std;

class cmp {
public:
	bool operator()(pair<int, int>&a, pair<int, int>&b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	}
};

class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<list<pair<int, int>>> graph(n, list<pair<int, int>>());
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			graph[v].push_back({u, wt});
			graph[u].push_back({v, wt});
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> ans;
		for (int i = 0; i < n; i++) {
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			unordered_map<int, int> mp;
			unordered_set<int> visited;
			for (int i = 0; i < n; i++) mp[i] = INT_MAX;
			pq.push({0, i});
			mp[i] = 0;
			while (pq.size()) {
				auto curr = pq.top();
				pq.pop();
				if (visited.count(curr.second)) continue;
				visited.insert(curr.second);
				for (auto node : graph[curr.second]) {
					if (!visited.count(node.first) && mp[node.first] > mp[curr.second] + node.second) {
						mp[node.first] = mp[curr.second] + node.second;
						pq.push({mp[curr.second] + node.second, node.first});
					}
				}
			}
			int cnt = 0;
			for (auto x : mp) {
				if (x.second <= distanceThreshold) cnt++;
			}
			ans.push({cnt, i});
		}
		return ans.top().second;
	}
};