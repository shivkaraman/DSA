
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&adjMat) {
		int n = adjMat.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adjMat[i][j] == -1) 
					adjMat[i][j] = INT_MAX;
				if (i == j) 
                    adjMat[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (adjMat[i][k] == INT_MAX || adjMat[k][j] == INT_MAX) continue;

					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
				}
			}
		}

	}
};


int main() {
	int V = 4;
	vector<vector<int>> adjMat(V, vector<int>(V, -1));
	adjMat[0][1] = 2;
	adjMat[1][0] = 1;
	adjMat[1][2] = 3;
	adjMat[3][0] = 3;
	adjMat[3][1] = 5;
	adjMat[3][2] = 4;

	Solution obj;
	obj.shortest_distance(adjMat);

	for (auto row : adjMat) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}