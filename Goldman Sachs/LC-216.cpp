#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size;
    void f(vector<int>& temp, int sum, int i) {
        if (sum == 0 && temp.size() == size) {
            ans.push_back(temp);
            return;
        }
        if (i >= arr.size()) return;
        if (sum - arr[i] >= 0) {
            temp.push_back(arr[i]);
            f(temp, sum - arr[i], i + 1);
            temp.pop_back();
        }
        f(temp, sum, i + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        size = k;
        vector<int> temp;
        f(temp, n, 0);
        return ans;
    }
};