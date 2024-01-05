#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int peopleAwareOfSecret(int n, int delay, int forget) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		int noOfPeopleSharingSecret = 0;
		int mod = 1e9 + 7;
		for (int i = 2; i <= n; i++) {
			int noOfNewPeopleSharingSecret = dp[max(i - delay, 0)];
			int noOfPeopleForgetingSecret = dp[max(i - forget, 0)];

			noOfPeopleSharingSecret = (noOfPeopleSharingSecret % mod + (noOfNewPeopleSharingSecret % mod - noOfPeopleForgetingSecret % mod + mod) % mod) % mod;

			dp[i] = noOfPeopleSharingSecret;
		}

		int ans = 0;

		for (int i = n - forget + 1; i <= n; i++) {
			ans = (ans % mod + dp[i] % mod) % mod;
		}
		return ans;
	}
};