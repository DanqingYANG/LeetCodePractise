#pragma once

/*101,10101,101010,true
  10,100,111,11100, false*/

class BinaryNumbersAlternating
{
public:
	BinaryNumbersAlternating() {};
	~BinaryNumbersAlternating() {};
	bool hasAlternatingBits(int n) {
		int b = n % 2;
		n = n / 2;
		while (n > 0)
		{
			if (n % 2 == b) return false;
			b = n % 2;
			n = n / 2;
		}
		return true;
	}

	void test() {
		BinaryNumbersAlternating s693;
		for (int i = 1; i < 22; i++)
		{
			bool b = s693.hasAlternatingBits(i);
			cout << i << " " << b << endl;
		}
	}
};

