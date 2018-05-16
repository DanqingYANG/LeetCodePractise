#pragma once
#include <iostream>
#include <vector>
using namespace std;

class FlippingAnImage
{
public:
	FlippingAnImage() {};
	~FlippingAnImage() {};
	vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
		vector<int> b;
		vector<vector<int> > B;
		int l1 = A.size();
		int l2 = A[0].size();
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				b.push_back ( (A[i][l2 - 1 - j] == 0 ? 1 : 0));	
			}
			B.push_back(b);
			b = {};
		}
		return B;
	}

	void test() {
		vector<vector <int> > a = { { 1, 1, 0, 0 },{ 1, 0, 0, 1 },{ 0, 1, 1, 1 },{ 1, 0, 1, 0 } };
		vector<vector <int> > b = flipAndInvertImage(a);
		print(a);
		cout << endl << "flip and reverse" << endl;
		print(b);
	}

	void print(vector<vector<int> > v) {
		cout << "{";
		for (int i = 0; i < v.size(); i++)
		{
			cout << "{";
			for (int j = 0; j < v[0].size(); j++)
			{
				cout << v[i][j] << ",";
			}
			cout << "}";
		}
		cout << "}";
	}
};

