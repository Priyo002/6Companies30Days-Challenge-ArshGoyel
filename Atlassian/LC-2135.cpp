#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		unordered_set<string> st;
		for (auto str : startWords) {
			string temp = str;
			sort(temp.begin(), temp.end());
			st.insert(temp);
		}

		int ans = 0;
		for (auto str : targetWords) {

			for (int i = 0; i < str.size(); i++) {
				string temp = str.substr(0, i) + str.substr(i + 1);
				sort(temp.begin(), temp.end());
				if (st.count(temp)) {
					ans++;
					break;
				}
			}
		}
		return ans;
	}
};