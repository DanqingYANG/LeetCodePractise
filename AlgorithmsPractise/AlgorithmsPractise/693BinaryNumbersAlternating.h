#pragma once

/*101,10101,101010,true
  10,100,111,11100, false*/

class BinaryNumbersAlternating
{
public:
	BinaryNumbersAlternating() {};
	~BinaryNumbersAlternating() {};
	bool hasAlternatingBits(int n) {
		bool b = n % 2;
		n = n / 2;
		while (n > 0)
		{
			if (n % 2 == b) return false;
			b = n % 2;
			n = n / 2;
		}
		return true;
	}
};

