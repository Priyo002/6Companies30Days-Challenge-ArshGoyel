#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int n, m;
	void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int r, int c) {
		int dir[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
		queue<pair<int, int>> qu;
		qu.push({r, c});
		visited[r][c] = true;

		while (qu.size()) {
			auto curr = qu.front();
			qu.pop();
			for (int d = 0; d < 4; d++) {
				int x = curr.first + dir[d][0];
				int y = curr.second + dir[d][1];
				if (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && graph[x][y] == 1) {
					qu.push({x, y});
					visited[x][y] = true;
				}
			}

		}
	}

	int noOfIslands(vector<vector<int>>& graph, int r, int c) {
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		if (r != -1 && c != -1)
			visited[r][c] = true;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 1 && !visited[i][j]) {
					cnt++;
					bfs(graph, visited, i, j);
				}
			}
		}
		return cnt;
	}
	int minDays(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		int fn = noOfIslands(grid, -1, -1);
		if (fn == 0 || fn > 1) return 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					int temp = noOfIslands(grid, i, j);
					if (temp != 1) return 1;
				}
			}
		}
		return 2;
	}
};