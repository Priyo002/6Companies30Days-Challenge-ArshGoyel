#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int n = isWater.size();
		int m = isWater[0].size();

		vector<vector<bool>> visited(n, vector<bool>(m, false));
		queue<pair<int, int>> qu;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isWater[i][j]) {
					qu.push({i, j});
					isWater[i][j] = 0;
					visited[i][j] = true;
				}
			}
		}
		int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
		int level = 0;
		while (qu.size()) {
			int cnt = qu.size();
			while (cnt--) {
				auto curr = qu.front();
				qu.pop();
				for (int d = 0; d < 4; d++) {
					int x = curr.first + dir[d][0];
					int y = curr.second + dir[d][1];
					if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y]) continue;
					qu.push({x, y});
					isWater[x][y] = 1 + level;
					visited[x][y] = true;
				}
			}
			level++;
		}
		return isWater;

	}
};