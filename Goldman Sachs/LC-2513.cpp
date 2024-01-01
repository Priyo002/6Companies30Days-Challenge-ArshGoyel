#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/

class Solution {
public:

    int minimizeSet(int d11, int d22, int Cnt1, int Cnt2) {
        long ans = 0;
        long start = 1;
        long end = 1e10;
        long d1 = d11, d2 = d22;
        while (start <= end) {
            long mid = start + (end - start) / 2;
            long a = mid - mid / d1;
            long b = mid - mid / d2;
            long lcm = ((d1 * d2) / __gcd(d1, d2));
            long c = mid - (mid / d1) - (mid / d2) + (mid / lcm);
            if (a >= Cnt1 && b >= Cnt2 && (a + b - c) >= Cnt1 + Cnt2) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return (int)ans;
    }
};