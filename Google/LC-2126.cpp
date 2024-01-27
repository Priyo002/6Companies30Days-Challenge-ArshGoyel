#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
		sort(asteroids.begin(), asteroids.end());
		long long currMass = mass;
		for (auto x : asteroids) {
			if (currMass >= x) {
				currMass += x;
			}
			else return false;
		}
		return true;
	}
};