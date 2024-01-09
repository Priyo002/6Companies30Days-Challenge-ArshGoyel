#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		vector<int> arr = nums;
		sort(arr.begin(), arr.end());

		int i = n - 1;
		for (int j = 1; j < n; j += 2) {
			nums[j] = arr[i--];
		}
		for (int j = 0; j < n; j += 2) {
			nums[j] = arr[i--];
		}
	}
};