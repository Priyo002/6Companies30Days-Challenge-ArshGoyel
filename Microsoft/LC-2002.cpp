#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int dp[15][15];
	int lcs(string& a, string& b, int i, int j) {
		if (i == a.size() || j == b.size()) return 0;
		if (dp[i][j] != -1) return dp[i][j];
		int ans = INT_MIN;
		if (a[i] == b[j]) {
			ans = max(ans, 1 + lcs(a, b, i + 1, j + 1));
		}
		ans = max(ans, lcs(a, b, i + 1, j));
		ans = max(ans, lcs(a, b, i, j + 1));
		return dp[i][j] = ans;
	}
	int f(string& str) {
		string temp = str;
		reverse(temp.begin(), temp.end());
		memset(dp, -1, sizeof(dp));
		return lcs(str, temp, 0, 0);
	}
	int maxProduct(string s) {
		int n = s.size();
		int ans = 1;
		for (int i = 0; i < (1 << n); i++) {
			string x = "", y = "";
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) x += s[j];
				else y += s[j];
			}
			ans = max(ans, (f(x) * f(y)));
		}
		return ans;
	}
};