#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,string>

class cmp {
public:
	bool operator()(const pp &a, const pp &b ) {
		if (a.first == b.first) return a.second > b.second;
		else return a.first < b.first;
	}
};

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> mp;
		for (int i = 0; i < words.size(); i++) {
			mp[words[i]]++;
		}
		priority_queue<pp, vector<pp>, cmp> pq;
		for (auto i : mp) {
			string s = i.first;
			int k = i.second;
			pq.push({k, s});
		}
		vector<string> ans;
		while (k-- && !pq.empty()) {
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;
	}
};