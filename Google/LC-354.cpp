#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	//LIS - Patience Sort
	bool static cmp(vector<int>&a, vector<int>&b) {
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	}
	int maxEnvelopes(vector<vector<int>>& arr) {
		sort(arr.begin(), arr.end(), cmp);
		vector<int> dp;
		int n = arr.size();
		for (auto it : arr) {
			int h = it[1];
			int left = lower_bound(dp.begin(), dp.end(), h) - dp.begin();
			if (left == dp.size()) dp.push_back(h);
			else dp[left] = h;
		}
		return dp.size();
	}
};