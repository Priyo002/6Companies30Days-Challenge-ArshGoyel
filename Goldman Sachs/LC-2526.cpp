#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/

class DataStream {
public:
	int cnt = 0;
	int val, kk;
	DataStream(int value, int k) {
		val = value, kk = k;
	}

	bool consec(int num) {
		if (num == val) cnt++;
		else cnt = 0;
		return cnt >= kk;
	}
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */