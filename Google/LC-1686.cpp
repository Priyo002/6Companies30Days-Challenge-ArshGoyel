#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		int n = aliceValues.size();
		vector<pair<int, pair<int, int>>> arr;
		for (int i = 0; i < n; i++) {
			arr.push_back({aliceValues[i] + bobValues[i], {aliceValues[i], bobValues[i]}});
		}
		sort(arr.rbegin(), arr.rend());
		int alice = 0, bob = 0;
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				bob += arr[i].second.second;
			}
			else {
				alice += arr[i].second.first;
			}
		}
		if (alice > bob) return 1;
		else if (alice < bob) return -1;
		else return 0;
	}
};