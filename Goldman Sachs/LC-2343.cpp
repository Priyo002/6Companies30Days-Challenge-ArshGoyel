#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

class Solution {
public:
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		vector<int> ans;
		for (auto it : queries) {
			int k = it[0];
			int trim = it[1];
			vector<pair<string, int>> temp;
			for (int i = 0; i < nums.size(); i++) {
				string str = nums[i].substr(nums[i].size() - trim);
				temp.push_back({str, i});
			}
			sort(temp.begin(), temp.end());
			ans.push_back(temp[k - 1].second);
		}
		return ans;
	}

};