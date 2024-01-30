#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int ans = 0;
	vector<int> f(int d, TreeNode* root) {
		if (root == NULL) return {0};
		if (root->left == NULL && root->right == NULL) return {1};

		auto l = f(d, root->left);
		auto r = f(d, root->right);

		for (auto a : l) {
			for (auto b : r) {
				if ((a && b) && a + b <= d) {
					ans++;
				}
			}
		}
		vector<int> temp;
		for (auto a : l) {
			if (a && a + 1 <= d) temp.push_back(a + 1);
		}
		for (auto b : r) {
			if (b && b + 1 <= d) temp.push_back(b + 1);
		}
		return temp;

	}
	int countPairs(TreeNode* root, int distance) {
		auto k = f(distance, root);
		return ans;
	}
};