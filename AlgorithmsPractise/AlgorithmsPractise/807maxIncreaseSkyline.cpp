#include "807maxIncreaseSkyline.h"



maxIncreaseSkyline::maxIncreaseSkyline()
{
}


maxIncreaseSkyline::~maxIncreaseSkyline()
{
}

int maxIncreaseSkyline::maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
{
	int grid_x = grid.size();
	int grid_y = grid[0].size();
	gridNew = grid;
	
	//initiate topBottom and leftRight
	//for (int i = 0; i < grid_x; i++)
	//{
	//	topBottom.push_back(0);
	//}
	//for (int i = 0; i < grid_y; i++)
	//{
	//	leftRight.push_back(0);
	//}

	for (int i = 0; i < grid_x; i++)
	{
		leftRight.push_back(0);
		for (int j = 0; j < grid_y; j++)
		{
			if (grid[i][j] > leftRight[i])
			{
				leftRight[i] = grid[i][j];
			}
		}
	}

	for (int i = 0; i < grid_y; i++)
	{
		topBottom.push_back(0);
		for (int j = 0; j < grid_x; j++)
		{
			if (grid[j][i] > topBottom[i])
			{
				topBottom[i] = grid[j][i];
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < grid_x; i++)
	{
		for (int j = 0; j < grid_y; j++)
		{
			if (topBottom[j] < leftRight[i]) {
				gridNew[i][j] = topBottom[j];
			}
			else
			{
				gridNew[i][j] = leftRight[i];
			}
			sum = sum + gridNew[i][j] - grid[i][j];
		}
	}
	return sum;
}