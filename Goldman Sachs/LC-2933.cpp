#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/high-access-employees/description/


bool cmp(string&a, string&b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return true;
}
class Solution {
public:
	bool f(vector<string> time) {
		sort(time.begin(), time.end(), cmp);
		int mx = 0;
		for (int i = 0; i < time.size(); i++) {
			int t1 = (1000 * (time[i][0] - '0')) + (100 * (time[i][1] - '0' + 1)) + (10 * (time[i][2] - '0')) + (time[i][3] - '0');
			int cnt = 1;
			for (int j = i + 1; j < time.size(); j++) {
				int t2 = (1000 * (time[j][0] - '0')) + (100 * (time[j][1] - '0')) + (10 * (time[j][2] - '0')) + (time[j][3] - '0');
				if (t2 < t1) cnt++;
			}
			mx = max(mx, cnt);
		}
		if (mx >= 3) return true;
		return false;
	}
	vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
		unordered_map<string, vector<string>> mp;
		for (int i = 0; i < arr.size(); i++) {
			mp[arr[i][0]].push_back(arr[i][1]);
		}
		vector<string> ans;
		for (auto it : mp) {
			bool flag = f(it.second);
			if (flag) ans.push_back(it.first);
		}
		return ans;
	}
};