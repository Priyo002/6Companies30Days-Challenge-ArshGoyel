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
	int amountOfTime(TreeNode* root, int start) {
		queue<TreeNode*> bfs;
		bfs.push(root);
		vector<list<int>> graph(100005, list<int>());
		while (bfs.size()) {
			auto curr = bfs.front();
			bfs.pop();
			if (curr->left) {
				graph[curr->val].push_back(curr->left->val);
				graph[curr->left->val].push_back(curr->val);
				bfs.push(curr->left);
			}
			if (curr->right) {
				graph[curr->val].push_back(curr->right->val);
				graph[curr->right->val].push_back(curr->val);
				bfs.push(curr->right);
			}
		}

		queue<int> qu;
		qu.push(start);
		vector<bool> visited(100005, false);
		visited[start] = true;
		int ans = 0;
		while (qu.size()) {
			int cnt = qu.size();
			while (cnt--) {
				auto curr = qu.front();
				qu.pop();

				for (auto node : graph[curr]) {
					if (visited[node] == false) {
						qu.push(node);
						visited[node] = true;
					}
				}
			}
			ans++;
		}
		return ans - 1;
	}
};