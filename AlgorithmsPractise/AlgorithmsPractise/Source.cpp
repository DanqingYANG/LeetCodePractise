using namespace std;
#include <iostream>
#include <vector>
#include "693BinaryNumbersAlternating.h"
#include "807maxIncreaseSkyline.h"

int main()
{
	//693
	BinaryNumbersAlternating s;
	for (int i = 1; i < 22; i++)
	{
		bool b = s.hasAlternatingBits(i);
		cout << i << " " << b << endl;
	}

	//807
	vector < vector<int> > g = { { 3, 0, 8, 4 },{ 2, 4, 5, 7 },{ 9, 2, 6, 3 },{ 0, 3, 1, 0 } };
	maxIncreaseSkyline s807;
	int sum = s807.maxIncreaseKeepingSkyline(g);
}