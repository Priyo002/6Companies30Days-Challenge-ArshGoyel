#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int mod = 1e9 + 7;
	long long power(long long a, long long b) {
		long long res = 1;
		while (b) {
			if (b & 1) res  = ((res % mod) * (a % mod)) % mod;
			b = (b >> 1);
			a = ((a % mod) * (a % mod)) % mod;
		}
		return res % mod;
	}
	int minNonZeroProduct(int p) {
		long long l = (1LL << p) - 1; //largest
		long long l1 = power(l - 1, (l - 1) / 2);
		long long l2 = power(1LL, (l - 1) / 2);
		long long ans = ((l % mod) * (l1 % mod) * (l2 % mod)) % mod;
		return (int)ans;

	}
};