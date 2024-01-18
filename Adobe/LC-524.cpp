#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool f(string a, string b) {
		int i = 0, j = 0;
		while (i < a.size() && j < b.size()) {
			if (a[i] == b[j]) {
				i++, j++;
			}
			else j++;
		}
		if (i == a.size()) return true;
		return false;
	}
	bool static cmp(string&a, string&b) {
		if (a.size() == b.size()) return a < b;
		return a.size() > b.size();
	}
	string findLongestWord(string s, vector<string>& dictionary) {

		sort(dictionary.begin(), dictionary.end(), cmp);

		for (auto str : dictionary) {
			if (f(str, s)) return str;
		}
		return "";
	}
};