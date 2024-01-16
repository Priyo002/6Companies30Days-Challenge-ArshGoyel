#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
        if (x == y) {
            ans += (x + y + z) * 2;
        }
        else if (x > y) {
            ans += (z + (y + 1) + y) * 2;
        }
        else ans += (z + (x + 1) + x) * 2;
        return ans;
    }
};