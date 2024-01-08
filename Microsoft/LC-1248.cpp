#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {

		int cnt = 0;
		unordered_map<char, int> mp;
		string ans = "";
		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i]) {
				guess[i] = '#';
				secret[i] = '#';
				cnt++;
			}
			else {
				mp[guess[i]]++;
			}
		}
		ans += to_string(cnt) + "A";
		cnt = 0;
		for (auto ch : secret) {
			if (ch == '#') continue;
			if (mp.count(ch)) {
				mp[ch]--;
				if (mp[ch] == 0) mp.erase(ch);
				cnt++;
			}
		}
		ans += to_string(cnt) + "B";
		return ans;
	}
};
