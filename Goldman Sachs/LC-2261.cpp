#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> st;

        for (int l = 0; l < n; l++) {
            vector<int> temp;
            int cnt = 0;
            for (int m = l; m < n; m++) {
                temp.push_back(nums[m]);
                if (nums[m] % p == 0) cnt++;
                if (cnt <= k) st.insert(temp);
            }
        }
        return st.size();

    }
};