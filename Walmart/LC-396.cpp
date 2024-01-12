#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxRotateFunction(vector<int>& nums) {
		int n = nums.size();
		int f0 = 0;
		int total = 0;
		for (int i = 0; i < n; i++) {
			f0 += (i * nums[i]);
			total += nums[i];
		}
		int ans = f0;
		int prev = f0;
		for (int i = n - 1; i >= 0; i--) {
			int k1 = prev + total - (n * nums[i]);
			ans = max(ans, k1);
			prev = k1;
		}
		return ans;
	}
};