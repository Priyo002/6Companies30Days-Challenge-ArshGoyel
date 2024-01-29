#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> z_function(string s) {
		int n = s.size();
		vector<int> z(n);
		int l = 0, r = 0;
		z[0] = n;
		for (int i = 1; i < n; i++) {
			if (i < r) {
				z[i] = min(r - i, z[i - l]);
			}
			while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
				z[i]++;
			}
			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
		}
		return z;
	}
	long long sumScores(string s) {
		vector<int> temp = z_function(s);
		long long ans = accumulate(temp.begin(), temp.end(), 0ll);
		return ans;

	}
};