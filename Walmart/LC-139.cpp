#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	unordered_set<string> st;
	vector<int> dp;
	bool f(int i, string s) {
		if (i == s.size()) return true;
		if (dp[i] != -1) return dp[i];
		string temp = "";
		for (int j = i; j < s.size(); j++) {
			temp += s[j];
			if (st.count(temp)) {
				if (f(j + 1, s)) return dp[i] = true;
			}
		}
		return dp[i] = false;
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		for (auto str : wordDict) {
			st.insert(str);
		}
		dp.clear();
		dp.resize(305, -1);
		return f(0, s);
	}
};