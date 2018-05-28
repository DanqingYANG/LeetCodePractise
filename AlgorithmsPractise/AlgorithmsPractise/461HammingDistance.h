#pragma once

// two numbers, compare
// choose the smaller one to compare two numbers
// count the rest "1"s in the bigger number
class HammingDistance
{
public:
	HammingDistance() {};
	~HammingDistance() {};

	int hammingDistance(int x, int y) {
		if (x == y) {
			return 0;
		}
		else if (x < y) {
			return hamming(x, y);
		}
		return hamming(y, x);
	}

	inline int hamming(int x, int y) //for all x,y, x < y
	{
		int ans = 0;
		while (y / 2 > 0)
		{
			while (x / 2 > 0 || x == 1) // when x == 1 , x/2 is 0. however this should be compared.
			{
				ans += (x % 2 == y % 2) ? 0 : 1;
				x = x / 2;
				y = y / 2;
			}
			//get the rest 1s
			ans += y % 2;
			y = y / 2;
		}
		if (y == 1)
		{
			ans++;
		}
		return ans;
	}

	void test() {

		double a = 4;
		double b = 4;
		//cout<<hammingDistance(a, b); 
		return;
	}
};

