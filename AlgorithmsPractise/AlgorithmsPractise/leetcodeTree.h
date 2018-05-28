#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class leetcodeTree
{
public:
	TreeNode* root;
	
	leetcodeTree(vector<int> input) 
	{
		root = buildTreeFromVec(input);
	};

	~leetcodeTree() {};
	
	//heap: input array, int arrayLength = sizeof(data) / sizeof(int);
	TreeNode* buildTreeFromArray(int a[], int arrayLength) {
		if (a == NULL) return NULL;
		TreeNode* root = new TreeNode{ a[0] };

		vector <TreeNode*>  tree;
		tree.push_back(root);

		for (int i = 1; i < arrayLength; i += 2)
		{
			int parentIndex = (i - 1) / 2;
			TreeNode* leftLeaf = new TreeNode{ a[i] };
			tree[parentIndex]->left = leftLeaf;
			tree.push_back(leftLeaf);
			if (i + 1 < arrayLength)
			{
				TreeNode* rightLeaf = new TreeNode{ a[i + 1] };
				tree[parentIndex]->right = rightLeaf;
				tree.push_back(rightLeaf);
			}
		}
		return tree[0];
	}

	//leetcode: input vector<int>
	TreeNode* buildTreeFromVec(vector<int> a) {
		TreeNode* root = new TreeNode{ a[0] };

		vector<TreeNode*> tree;
		tree.push_back(root);
		for (int i = 1; i < a.size(); i = i + 2) {
			TreeNode* cur = tree.back();
			tree.pop_back();
			TreeNode* leftleaf = new TreeNode(a[i]);
			cur->left = leftleaf;
			tree.insert(tree.begin(), leftleaf);
			if (i + 1 > a.size()) break;
			TreeNode* rightleaf = new TreeNode(a[i + 1]);
			cur->right = rightleaf;
			tree.insert(tree.begin(), rightleaf);
		}
		return root;
	}
};

