#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool f(int i, int j, vector<int>& arr) {
		vector<int> temp;
		for (int k = 0; k < arr.size(); k++) {
			if (k >= i && k <= j) continue;
			temp.push_back(arr[k]);
		}
		for (int i = 1; i < temp.size(); i++) {
			if (temp[i] <= temp[i - 1]) return false;
		}
		return true;
	}
	int incremovableSubarrayCount(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				ans += f(i, j, nums);
			}
		}
		return ans;
	}
};