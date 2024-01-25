#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countCollisions(string directions) {
		stack<char> st;
		int ans = 0;
		for (auto ch : directions) {
			if (ch == 'R') {
				st.push(ch);
			}
			else if (ch == 'S') {
				int cnt = 0;
				while (st.size() && st.top() == 'R') {
					cnt++;
					st.pop();
				}
				ans += cnt;
				st.push(ch);
			}
			else if (ch == 'L') {
				if (st.size() && st.top() == 'S') {
					ans++;
				}
				else {
					int cnt = 0;
					while (st.size() && st.top() == 'R') {
						cnt++;
						st.pop();
					}
					ans += max(0, (cnt - 1));
					if (cnt > 0) {
						ans += 2;
						st.push('S');
					}
				}
			}
		}
		return ans;
	}
};