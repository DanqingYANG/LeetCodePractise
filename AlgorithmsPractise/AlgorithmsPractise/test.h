#494
#pragma once
#include <vector>
using namespace std;
class Solution {
public:
	struct TreeNode
	{
		int number;
		TreeNode * parent;
	};

	bool qualifiedCombi(TreeNode* currentNode, int S)
	{
		int sum = 0;
		while (currentNode->parent != nullptr)
		{
			sum = sum + currentNode->number;
			currentNode = currentNode->parent;
			//cout << currentNode->number << " ";
		}
		if (sum == S) {
			//cout << endl << sum << endl;
			return true;
		}
		return false;
	}

	vector<TreeNode* > buildTree(vector<TreeNode* > Parents, int num)
	{
		vector<TreeNode* > Children;
		int n = static_cast<int>(Parents.size());
		for (int i = 0; i < n; i++)
		{
			TreeNode* leftchild = new TreeNode{ num, Parents[n - 1 - i] };
			TreeNode* rightchild = new TreeNode{ -num, Parents[n - 1 - i] };;

			//TreeNode rightchild = { -num, Parents[ n -1 - i ] };
			Children.push_back(leftchild);
			Children.push_back(rightchild);
			Parents.pop_back();
		}
		return Children;
	}

	int findTargetSumWays(vector<int>& nums, int S)
	{
		vector<TreeNode* > currentLevel;
		TreeNode root = { 0, nullptr };
		currentLevel.push_back(&root);

		int n = static_cast<int>(nums.size()); // static_cast is needed here
		for (int i = 0; i < n; i++)
		{
			currentLevel = buildTree(currentLevel, nums[i]);
		}

		int qualifiedCases = 0;
		n = static_cast<int>(currentLevel.size());
		for (int i = 0; i < n; i++)
		{
			if (qualifiedCombi(currentLevel[i], S))
			{
				qualifiedCases = qualifiedCases + 1;
			}
		}
		return qualifiedCases;
	}

	void test() {
		Solution s;
		vector<int> v = { 19,32,36,7,37,10,44,21,40,39,39,18,5,34,3,40,33,2,46,46 };
		s.findTargetSumWays(v, 29);
	}
    
};

