#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		int i = 0;
		int j = 0;
		int cnt = 0;
		int ans = 0;
		int odd = 0;
		while (j < n) {
			if (nums[j] % 2 != 0) {
				cnt = 0;
				odd++;
			}
			while (i <= j && odd == k) {
				cnt++;
				if (nums[i++] % 2 != 0 ) odd--;
			}
			ans += cnt;
			j++;
		}
		return ans;
	}
};