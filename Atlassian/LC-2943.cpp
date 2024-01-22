#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
		sort(hBars.begin(), hBars.end());
		sort(vBars.begin(), vBars.end());
		int mxH = 0;
		int mxV = 0;
		int cnt = 1;
		for (int i = 0; i < hBars.size() - 1; i++) {
			if (hBars[i] + 1 == hBars[i + 1]) {
				cnt++;
			}
			else {
				mxH = max(mxH, cnt);
				cnt = 1;
			}
		}
		mxH = max(mxH, cnt);
		cnt = 1;
		for (int i = 0; i < vBars.size() - 1; i++) {
			if (vBars[i] + 1 == vBars[i + 1]) {
				cnt++;
			}
			else {
				mxV = max(mxV, cnt);
				cnt = 1;
			}
		}
		mxV = max(mxV, cnt);
		int val = min(mxV, mxH) + 1;
		return val * val;
	}
};