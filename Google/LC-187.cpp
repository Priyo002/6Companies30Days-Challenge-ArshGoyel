#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string decode(string s) {
		string temp = "";
		if (s.size() == 3) {
			string t1 = string(10, s[0]);
			return t1;
		}
		for (int i = 1; i < s.size(); i += 2) {
			char ch = s[i - 1];
			int cnt = s[i] - '0';
			string t = "";
			while (cnt--) {
				t += ch;
			}
			temp += t;
		}
		return temp;
	}
	vector<string> findRepeatedDnaSequences(string s) {
		int i = 0, j = 9;
		vector<string> ans;
		unordered_map<string, int> mp;
		while (j < s.size()) {
			string str = "";
			for (int k = i; k <= j; k++) {
				char ch = s[k];
				int l = k;
				int cnt = 0;
				while (l <= j && s[l] == ch) {
					cnt++;
					l++;
				}
				k = l - 1;
				str += ch + to_string(cnt);
			}
			mp[str]++;
			i++;
			j++;
		}
		for (auto x : mp) {
			if (x.second > 1) {
				//cout << x.first << " ";
				string temp = decode(x.first);
				ans.push_back(temp);
			}
		}
		return ans;

	}
};