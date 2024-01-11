#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<int> arr = nums;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		unordered_map<int, int> mp;
		for (int i = n - k; i < n; i++) {
			mp[nums[i]]++;
		}
		vector<int> ans;
		for (auto x : arr) {
			if (mp.count(x)) {
				ans.push_back(x);
				mp[x]--;
				if (mp[x] == 0) mp.erase(x);
			}
		}

		return ans;
	}
};