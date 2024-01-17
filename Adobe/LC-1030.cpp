#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
		vector<pair<int, pair<int, int>>> temp;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int d = abs(rCenter - i) + abs(cCenter - j);
				temp.push_back({d, {i, j}});
			}
		}

		sort(temp.begin(), temp.end());
		vector<vector<int>> ans;
		for (auto x : temp) {
			vector<int> t = {x.second.first, x.second.second};
			ans.push_back(t);
		}
		return ans;
	}
};