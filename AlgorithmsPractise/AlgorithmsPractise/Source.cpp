#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include "dataInterface.h"

using namespace std;

class Solution {
public:

	int findroot(int n, vector<int> v) {
		if (v[n] > -1) {
			n = v[n];
		}
		return n;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//DSU: init
		vector<int> dsu;
		bool canfinish = true;

		for (int i = 0; i < numCourses; i++)
		{
			dsu.push_back(-1);
		}

		for (int i = 0; i < prerequisites.size(); i++) {
			int node1 = prerequisites[i].first;
			int node2 = prerequisites[i].second;

			if (node1 == node2) {
				return false;
			}

			int r1 = findroot(node1, dsu);
			int r2 = findroot(node2, dsu);

			if (r1 < r2) {
				dsu[node2] = node1;
			}
			else if (r2 < r1) {
				dsu[node1] = node2;
			}
			else {
				if (r1 == -1) {
					dsu[node2] = node1;
				}
				else {
					canfinish = false;
					break;
				}
			}

		}

		return canfinish;

	}

	void test() {
		string s = "[[0,1],[0,2],[1,2]]";
		int n = 3;
		vector<pair<int,int> > v = stringToGraph_edge(s);
		cout << canFinish(n, v);

		return;
	}
};


int main()
{
	Solution s;
	s.test();

	return 0;
}



