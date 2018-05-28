/*
226.InvertBinaryTree
层序遍历,每次出一个parent，按层交换swap(*parent)的left and right children，children进栈
*/
#pragma once
#include <vector>
#include "leetcodeTree.h"

class InvertBinaryTree
{
public:
	InvertBinaryTree() {};
	~InvertBinaryTree() {};
	TreeNode * invertTree(TreeNode* root) {
		vector <TreeNode*> tree;
		tree.push_back(root);

		while (!tree.empty())
		{
			TreeNode* cur = tree.back();
			// Swap the children of the current TreeNode.
			swapTreeNode(cur);
			tree.pop_back();
			// Put the non-null children in the vector. 
			if (cur->left != nullptr)
				tree.push_back(cur->left);
			if (cur->right != nullptr)
				tree.push_back(cur->right);
		}
		return root;
	}

	inline void swapTreeNode(TreeNode* parent)
	{
		if (parent == nullptr) return;
		TreeNode* temp = parent->left;
		parent->left = parent->right;
		parent->right = temp;
	}

	void test()
	{
		leetcodeTree lt({ 4,2,7,1,3,6,9 });
		TreeNode* invert = invertTree(lt.root);
	}

};

