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
class nodeValue {
public:
	int min;
	int max;
	int sum;
	nodeValue(int min, int max, int sum)
	{
		this->min = min;
		this->max = max;
		this->sum = sum;
	}
};
class Solution {
public:
	int ans = 0;
	nodeValue f(TreeNode* root) {
		if (root == NULL)
			return nodeValue(INT_MAX, INT_MIN, 0);
		nodeValue left = f(root->left);
		nodeValue right = f(root->right);
		if (root->val > left.max && root->val < right.min)
		{
			ans = max(ans, root->val + left.sum + right.sum);
			return nodeValue(min(root->val, left.min), max(root->val, right.max), left.sum + root->val + right.sum);
		}
		return nodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum));
	}
	int maxSumBST(TreeNode* root) {
		f(root);
		return ans;
	}
};