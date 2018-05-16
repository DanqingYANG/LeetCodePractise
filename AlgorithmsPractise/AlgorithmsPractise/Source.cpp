using namespace std;
#include <iostream>
#include <vector>
#include "693BinaryNumbersAlternating.h"
#include "807maxIncreaseSkyline.h"
#include "832FlippingAnImage.h"

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
		for ( int i = 0; i < n; i++)
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
};

int main()
{
	//832
	FlippingAnImage f;
	f.test();
	//int ar[4] = { 1,2,3,4 };
	

	//494 not solved
	Solution s;
	vector<int> v = { 19,32,36,7,37,10,44,21,40,39,39,18,5,34,3,40,33,2,46,46 };
	s.findTargetSumWays(v, 29);

	//693
	BinaryNumbersAlternating s693;
	for (int i = 1; i < 22; i++)
	{
		bool b = s693.hasAlternatingBits(i);
		cout << i << " " << b << endl;
	}

	//807
	vector < vector<int> > g = { { 3, 0, 8, 4 },{ 2, 4, 5, 7 },{ 9, 2, 6, 3 },{ 0, 3, 1, 0 } };
	maxIncreaseSkyline s807;
	int sum = s807.maxIncreaseKeepingSkyline(g);
}