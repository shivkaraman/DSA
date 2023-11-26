// 1. You are given a 2d array where 0's represent land and 1's represent water.
//      Assume every cell is linked to it's north, east, west and south cell.
// 2. You are required to find and count the number of islands.

//This is an application on CONNECTED COMPONENTS
//In this question all elements of a 2d array are nodes of a graph and each node is connected to all of its adjascent elements

#include <iostream>
#include <vector>
using namespace std;

//Level-> Each element in 2D array
//4 options at each level -> go L or R or T or B (ie all the adjascent nodes are neighbors)
//This function checks for all connected 0's and marks them visited
void getConnnectedComponents(vector<vector<int>> arr, vector<vector<int>> &visited, int i, int j){
	if(i >= arr.size() || i < 0 || j >= arr[i].size() || j < 0 || arr[i][j] != 0 || visited[i][j] == true)
		return;
	
	visited[i][j] = true;
	getConnnectedComponents(arr, visited, i+1, j);
	getConnnectedComponents(arr, visited, i-1, j);
	getConnnectedComponents(arr, visited, i, j+1);
	getConnnectedComponents(arr, visited, i, j-1);
}

int main(){
	int n, m;
	cin >> n;
	cin >> m;

	vector<vector<int>> arr;
	for (int i = 0; i < n; i++){
		vector<int> temp;
		for (int j = 0; j < m; j++){
			int res;
			cin >> res;
			temp.push_back(res);
		}
		arr.push_back(temp);
	}

	vector<vector<int>> visited(n, vector<int>(m, false));
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//Mark all 0's contributing current island and mark them as true and increment count
			if(visited[i][j] == false && arr[i][j] == 0){
				getConnnectedComponents(arr, visited, i, j);
				count++;
			}
		}
	}
	cout << count << endl;
}