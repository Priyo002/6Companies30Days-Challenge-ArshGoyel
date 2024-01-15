#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	unordered_set<string> st;
	int dp[51];
	int f(string& s, int idx) {
		if (idx >= (int)s.size()) return 0;
		if (dp[idx] != -1) return dp[idx];

		int ans = INT_MAX;
		string str = "";

		for (int i = idx; i < s.size(); i++) {
			str.push_back(s[i]);

			if (st.find(str) != st.end()) {
				ans = min(ans, f(s, i + 1));
			}
			else {
				int k = str.size();
				ans = min(ans, k + f(s, i + 1));
			}
		}
		return dp[idx] = ans;
	}
	int minExtraChar(string s, vector<string>& dictionary) {
		for (auto x : dictionary) st.insert(x);
		memset(dp, -1, sizeof(dp));
		return f(s, 0);
	}
};