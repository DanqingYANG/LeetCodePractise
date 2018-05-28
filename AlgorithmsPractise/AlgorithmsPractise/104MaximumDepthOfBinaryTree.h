#pragma once
#include "leetcodeTree.h"
using  namespace std;

class MaximumDepthOfBinaryTree
{
public:
	MaximumDepthOfBinaryTree() {};
	~MaximumDepthOfBinaryTree() {};

	//recursive way
	int maxDepth(TreeNode* root) {
		int max = 0;
		dfs(root, 0, max);
		return max;
	}

	void dfs(TreeNode* t, int count, int& max) {
		if (t == nullptr) {
			max = count > max ? count : max;
			return;
		}

		count++;
		dfs(t->left, count, max);
		dfs(t->right, count, max);
		return;
	}

	//iterative way not finished
	/*int maxDepthIteration(TreeNode* t) {
		int layer = 0;
		vector<TreeNode*> ts;
		ts.push_back(t);
		
		return layer;
	}*/

	void test() {
		//int data[] = { 3, 9, 20, NULL, NULL, 15, 7,NULL,NULL,NULL,NULL,NULL,8 };
		//int arrayLength = sizeof(data) / sizeof(int);
		vector<int> input = { 3, 9, 20, NULL, NULL, 15, 7,NULL,NULL,NULL,NULL,NULL,8 };
		leetcodeTree aTree(input);//bulid a tree
		cout << maxDepth(aTree.root);
		return;
	}
};

