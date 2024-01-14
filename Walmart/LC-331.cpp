#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		int vacancy = 1;
		vector<string> arr;
		string temp = "";
		for (auto ch : preorder) {
			if (ch == ',') {
				arr.push_back(temp);
				temp = "";
			}
			else temp.push_back(ch);
		}
		arr.push_back(temp);

		for (auto ch : arr) {
			vacancy--;
			if (vacancy < 0) return false;
			if (ch != "#")
				vacancy += 2;
		}
		return vacancy == 0;
	}
};