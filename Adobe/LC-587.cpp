#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int f(pair<int, int>& p1, pair<int, int>& p2, pair<int, int> p3) {
		int x1 = p1.first, x2 = p2.first, x3 = p3.first;
		int y1 = p1.second, y2 = p2.second, y3 = p3.second;

		return ((long long)(y3 - y2) * (long long)(x2 - x1)) - ((long long)(y2 - y1) * (long long)(x3 - x2));
	}
	vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
		sort(trees.begin(), trees.end());

		vector<vector<int>> res;

		deque<pair<int, int>> upper, lower;

		for (auto point : trees) {
			int l = lower.size();
			int u = upper.size();

			while (l >= 2 && f(lower[l - 2], lower[l - 1], {point[0], point[1]}) < 0) {
				l--;
				lower.pop_back();
			}

			while (u >= 2 && f(upper[u - 2], upper[u - 1], {point[0], point[1]}) > 0) {
				u--;
				upper.pop_back();
			}

			upper.push_back({point[0], point[1]});
			lower.push_back({point[0], point[1]});
		}

		set<pair<int, int>> st;

		for (auto it : upper) st.insert(it);
		for (auto it : lower) st.insert(it);

		for (auto it : st) {
			res.push_back({it.first, it.second});
		}
		return res;
	}
};