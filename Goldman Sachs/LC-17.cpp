#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> ans;
    map<char, string>m;
    void f(string& digits, string& s, int i) {
        if (s.size() == digits.size()) {
            ans.push_back(s);
            return;
        }
        for (auto x : m[digits[i]]) {
            s.push_back(x);
            f(digits, s, i + 1);
            s.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string s;
        f(digits, s, 0);
        return ans;
    }
};