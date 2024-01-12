#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		for (auto x : nums) mp[x]++;
		int cnt = 0;
		for (auto i : mp) {
			int val = i.first + k;
			if (k == 0) {
				if (mp.find(val) != mp.end() && mp[val] > 1) {
					cnt++;
				}
			}
			else if (mp.find(val) != mp.end()) {
				cnt++;
			}
		}
		return cnt;
	}
};