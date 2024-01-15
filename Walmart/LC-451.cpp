#include<bits/stdc++.h>
using namespace std;



#define pp pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        priority_queue<pp> pq;
        for (auto i : mp) {
            char key = i.first;
            int val = i.second;
            pq.push({val, key});
        }
        string ans = "";
        while (!pq.empty()) {
            pp curr = pq.top();
            pq.pop();
            for (int i = 0; i < curr.first; i++) {
                ans.push_back(curr.second);
            }
        }
        return ans;
    }
};