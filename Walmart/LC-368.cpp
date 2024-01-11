#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {

		int n = nums.size();
		vector<int> dp(n + 1, 1), hash(n + 1, 0);
		for (int i = 0; i < n; i++) hash[i] = i;

		int maxi = 1, maxIdx = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i - 1; j++) {
				if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
					dp[i] = 1 + dp[j];
					hash[i] = j;
				}
			}
			if (dp[i] > maxi) {
				maxIdx = i;
				maxi = dp[i];
			}
		}

		vector<int> ans;
		ans.push_back(nums[maxIdx]);
		while (hash[maxIdx] != maxIdx) {
			maxIdx = hash[maxIdx];
			ans.push_back(nums[maxIdx]);
		}
		return ans;
	}
};