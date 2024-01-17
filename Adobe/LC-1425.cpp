#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Like LIS
	int constrainedSubsetSum(vector<int>& nums, int k) {
		int n = nums.size();

		priority_queue<pair<int, int>> pq;
		vector<int> dp = nums;
		pq.push({nums[0], 0});
		for (int i = 1; i < n; i++) {
			while (pq.size() && i - pq.top().second > k) {
				pq.pop();
			}
			dp[i] = max(dp[i], nums[i] + pq.top().first);
			pq.push({dp[i], i});
		}
		return *max_element(dp.begin(), dp.end());
	}
};