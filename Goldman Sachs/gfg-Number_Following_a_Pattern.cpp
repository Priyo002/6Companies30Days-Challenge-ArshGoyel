#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	string printMinNumberForPattern(string S) {
		// code here
		stack<int> st;
		string ans = "";
		int num = 1;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'D') {
				st.push(num);
				num++;
			}
			else {
				st.push(num);
				num++;
				while (st.size()) {
					ans += to_string(st.top());
					st.pop();
				}
			}
		}
		st.push(num);
		while (st.size()) {
			ans += to_string(st.top());
			st.pop();
		}
		return ans;
	}
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string S;
		cin >> S;
		Solution ob;
		cout << ob.printMinNumberForPattern(S) << endl;
	}
	return 0;
}

// } Driver Code Ends