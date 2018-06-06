#include <iostream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;



int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string n ="";
	string st = "";
	string odd = "";
	string even = "";
	
	getline(cin, n);
	int q = stoi(n);
	for (int i = 0; i < q; i++) {
		getline(cin,st);
		for (int j = 0; j < st.size(); j+= 1) {
			if (j % 2 == 1) {
				odd.append(1, st[j]);
			}
			else {
				even.append(1, st[j]);
			}
		}
		cout << even << " " << odd << endl;
		st = "";
		even = "";
		odd = "";
	}
	return 0;
}



