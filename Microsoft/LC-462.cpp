#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int avg;
        if (n % 2 == 0) {
            avg = (nums[n / 2] + nums[n / 2 - 1]) / 2;
        }
        else avg = nums[n / 2];
        int ans = 0;
        for (auto x : nums) {
            ans += abs(x - avg);
        }
        return ans;
    }
};