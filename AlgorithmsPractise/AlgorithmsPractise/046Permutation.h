#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Permutation
{
public:
	Permutation(){};
	~Permutation() {};

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		res = generate(nums, 4, res);
		return res;
	}
	//Permutate all possibilities of the first [size] elements, keep the left elements fixed
	vector<vector<int>> generate(vector<int>& nums, int size, vector<vector<int>>& a) {
		if (size == 1) {//If size == 1, only one possibility, save it
			a.push_back(nums);
			for (int i = 0; i < nums.size(); i++)
				cout << nums[i];
			cout << "\n";
			return a;
		}

		for (int i = 0; i < size; i++) {
			//Keep the last element fixed, permutate all possibilites of all first [size-1] elements, the last element, [size-1]th element, will be fixed
			generate(nums, size - 1, a);
			if (size % 2 == 1)
				swap(nums[0], nums[size - 1]);
			else
				swap(nums[i], nums[size - 1]);
		}
		return a;
	}
		void test() 
		{
			Permutation p;
			vector<int> v = { 1,2,3,4,5 };
			vector<vector<int> > b = p.permute(v);
		}
};