#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <set>
using namespace std;

class Solution {

public:
	bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
		map<int, vector<int>> my_map;
		map<int, int> degrees;
		for (auto a : prerequisites) {
			degrees[a.first] = 0, degrees[a.second] = 0;
			my_map[a.first].push_back(a.second);
		}

		for (auto a : prerequisites) {
			degrees[a.second] += 1;
		}
		queue<int> q;
		for (auto a : degrees) {
			if (a.second == 0) {
				q.push(a.first);
			}
		}
		int counter = 0;
		while (!q.empty()) {
			int node = q.front();
			counter++;
			q.pop();
			for (auto a : my_map[node]) {
				degrees[a]--;
				if (degrees[a] == 0) {
					q.push(a);
				}
			}
		}
		
		if (counter != degrees.size()) {
			return false;
		}
		return true;
	}
};



int main() {


	vector<char> vis(8, '\0');
	vector<int> graph[] = { {}, {}, {3}, {1}, {0, 1}, {0, 2} };
	vector<int> graph_2[] = { {1, 2}, {3}, {5}, {0}, {5}, {}, {} };
	vector<pair<int, int>> my_pair = { 
		{1, 25},
		{10, 64},
		{16, 10},
		{19, 61},
		{21, 31},
		{28, 53},
		{31, 56},
		{34, 7},
		{36, 20},
		{40, 27},
		{45, 48},
		{46, 52},
		{47, 30},
		{47, 39},
		{49, 10},
		{51, 2} };

	vector<pair<int, int>> my_pair_2 = { {1, 0}, {0, 1} };
	Solution solu;
	if (solu.isPossible(68, 16, my_pair_2)) cout << "Yes" << endl;

	map<int, vector<int>> m;

	
	
	
	
	
	
	

}