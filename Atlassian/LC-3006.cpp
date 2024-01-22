#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> beautifulIndices(string s, string a, string b, int k) {

		vector<int> aidx, bidx;

		int n = s.size();

		for (int i = 0; i < n; i++) {
			if (s[i] == a[0]) {
				int j = i;
				int l = 0;
				string temp = "";
				while (j < n && s[j] == a[l]) {
					temp += a[l];
					j++;
					l++;
				}
				if (temp == a) {
					aidx.push_back(i);
				}
			}
			if (s[i] == b[0]) {
				int j = i;
				int l = 0;
				string temp = "";
				while (j < n && s[j] == b[l]) {
					temp += b[l];
					j++;
					l++;
				}
				if (temp == b) {
					bidx.push_back(i);
				}
			}
		}
		// for(auto x : aidx) cout << x << " ";
		// cout <<endl;
		// for(auto x : bidx) cout << x << " ";
		// cout << endl;

		vector<int> ans;
		if (bidx.size() == 0) return ans;


		for (auto x : aidx) {
			int lo = lower_bound(bidx.begin(), bidx.end(), x) - bidx.begin();
			if (lo == bidx.size()) lo--;
			int m = bidx.size() - 1;
			for (int j = max(0, lo - 2); j <= min(m, lo); j++) {
				if (abs(x - bidx[j]) <= k) {
					ans.push_back(x);
					break;
				}
			}
		}

		return ans;
	}
};