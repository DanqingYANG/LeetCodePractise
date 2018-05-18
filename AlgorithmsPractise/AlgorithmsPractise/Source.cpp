using namespace std;
#include <iostream>
#include <vector>

#include "693BinaryNumbersAlternating.h"
#include "807maxIncreaseSkyline.h"
#include "832FlippingAnImage.h"
#include "046Permutation.h"


///


 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	//Solution 1 : add t2 to t1
	//Solution 2 : build a new tree add as many trees as possible, will be more flexible



	//Solution 1 : add t2 to t1
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		t1->val = t1->val + t2->val;
		if(t1 != NULL && t2 != NULL)
			CombineBranches(t1, t2);
		return t1;
	}


	void CombineBranches(TreeNode* t1, TreeNode* t2) {
		t1->val = t1->val + t2 ->val;
		if (t2->left == NULL && t2->right == NULL)//endpoint of t2
			return;
		//else t1 Null,  adjust the point
		else 
		{

			CombineBranches(t1->left, t2->left);
			CombineBranches(t1->right, t2->left);
		}
	}



	int addValues(TreeNode * t1, TreeNode* t2)
	{
		if (t1 != NULL)
		{
			if (t2 != NULL) {
				t1->val = t2->val + t1->val; 
			}
		}
		else {
			if (t2 != NULL) {
				t1->val = t2 -> val;
			}
		}
	}

};

int main()
{
	Solution s;

	//832
	FlippingAnImage f;
	f.test();

	//494 
	

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