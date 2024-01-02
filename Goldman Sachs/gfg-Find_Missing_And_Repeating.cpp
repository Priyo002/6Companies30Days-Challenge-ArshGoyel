//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// } Driver Code Ends
class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int correctIdx = arr[i] - 1;
            if (arr[i] == i + 1) continue;
            if (arr[correctIdx] == arr[i]) {
                if (ans.size()) continue;
                ans.push_back(arr[i]);
            }
            else {
                swap(arr[correctIdx], arr[i]);
                i--;
            }
        }
        //for(auto x : arr) cout << x << " ";
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                ans.push_back(i + 1);
                return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends