#include<bits/stdc++.h>
using namespace std;

class ThroneInheritance {
public:
	unordered_map<string, list<string>> mp;
	unordered_set<string> st;
	string king;
	ThroneInheritance(string kingName) {
		king = kingName;
	}

	void birth(string parentName, string childName) {
		mp[parentName].push_back(childName);
	}

	void death(string name) {
		st.insert(name);
	}

	void dfs(string curr, vector<string>& ans) {
		if (st.count(curr) == 0)
			ans.push_back(curr);
		for (auto node : mp[curr]) {
			dfs(node, ans);
		}
	}

	vector<string> getInheritanceOrder() {
		string name = king;
		vector<string> ans;
		dfs(name, ans);
		return ans;
	}
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */