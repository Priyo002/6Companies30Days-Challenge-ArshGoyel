#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		int n = nums.size();
		priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

		while (k--) {
			int curr = pq.top();
			pq.pop();
			pq.push(curr + 1);
		}
		long long ans = 1, mod = 1e9 + 7;
		while (pq.size()) {
			ans = ((ans % mod) * (pq.top() % mod)) % mod;
			pq.pop();
		}
		return (int)ans;
	}
};