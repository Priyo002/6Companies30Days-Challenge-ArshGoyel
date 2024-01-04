#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/run-length-encoding/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main() {

	int T;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;

		cout << encode(str) << endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{
	//Your code here
	string ans = "";
	for (int i = 0; i < src.size(); i++) {
		int j = i;
		int cnt = 0;
		while (j < src.size() && src[i] == src[j]) {
			cnt++;
			j++;
		}
		i = j - 1;
		ans += src[i];
		ans += (char)(48 + cnt);
	}
	return ans;
}

