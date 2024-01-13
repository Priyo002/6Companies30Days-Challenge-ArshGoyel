#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		sort(ages.begin(), ages.end());
		int n = ages.size();
		int ans = 0;
		for (auto x : ages) {
			int val = x / 2 + 7;
			//if(x<=val) continue;
			int i = upper_bound(ages.begin(), ages.end(), val) - ages.begin();
			int j = upper_bound(ages.begin(), ages.end(), x) - ages.begin();
			j--;
			ans += max(0, j - i);
		}
		return ans;
	}
};