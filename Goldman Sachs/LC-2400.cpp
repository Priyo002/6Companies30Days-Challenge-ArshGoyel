#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/

class Solution {
public:
	int mod = 1e9 + 7;
	int dp[1006][10000];
	int f(int k, int s, int e) {
		if (s == e && k == 0) {
			return 1;
		}
		if (dp[k][1000 + s] != -1) return dp[k][1000 + s];
		int ans = 0;
		if (k > 0) {
			ans = (ans % mod + f(k - 1, s - 1, e) % mod) % mod;
			ans = (ans % mod + f(k - 1, s + 1, e) % mod) % mod;
		}
		return dp[k][1000 + s] = ans % mod;
	}
	int numberOfWays(int startPos, int endPos, int k) {
		memset(dp, -1, sizeof dp);
		return f(k, startPos, endPos);
	}
};