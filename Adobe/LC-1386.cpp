#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
		sort(arr.begin(), arr.end());

		int ans = 0;
		unordered_set<int> rows;

		for (int i = 0; i < arr.size(); i++) {
			rows.insert(arr[i][0]);
			vector<int> temp(11, 0);
			int row = arr[i][0];
			int k = i;
			while (k < arr.size() && row == arr[k][0]) {
				temp[arr[k][1]]++;
				k++;
			}
			i = k - 1;
			int cnt = 0;
			bool f1 = true, f2 = true, f3 = true;
			for (int i = 2; i <= 9; i++) {
				if (temp[i]) {
					if (i >= 2 && i <= 5) f1 = false;
					if (i >= 4 && i <= 7) f2 = false;
					if (i >= 6 && i <= 9) f3 = false;
				}
			}
			if (f1 && f3) cnt += 2;
			else if (f1 || f2 || f3) cnt++;

			ans += cnt;
		}
		int l = rows.size();
		if (l == n) return ans;
		else {
			ans += (n - l) * 2;
			return ans;
		}

	}
};