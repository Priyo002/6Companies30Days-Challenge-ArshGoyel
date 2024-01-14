#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int n = board.size();
		int m = board[0].size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'X') {
					if ((i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X')) continue;
					ans++;
				}
			}
		}

		return ans;
	}
};