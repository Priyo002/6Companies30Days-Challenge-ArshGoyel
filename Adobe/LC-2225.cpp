#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {

		map<int, int> winner, loser;
		for (int i = 0; i < matches.size(); i++) {
			winner[matches[i][0]]++;
			loser[matches[i][1]]++;
		}
		vector<int> a, b;
		for (auto x : loser) {
			if (winner.find(x.first) != winner.end()) {
				winner.erase(x.first);
			}
			if (x.second == 1) {
				b.push_back(x.first);
			}
		}
		for (auto x : winner) a.push_back(x.first);
		return {a, b};
	}
};