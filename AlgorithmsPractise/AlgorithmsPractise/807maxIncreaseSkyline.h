#pragma once
#include <vector>
using namespace std;

class maxIncreaseSkyline
{
public:
	maxIncreaseSkyline();
	~maxIncreaseSkyline();
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid);

private:
	vector<int> topBottom;
	vector<int> leftRight;
	vector<vector<int> > gridNew;
};

