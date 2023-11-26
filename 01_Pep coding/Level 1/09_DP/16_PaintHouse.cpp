/*
1. You are given a number n, representing the number of houses.
2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

Sample Input
4
1 5 7
5 8 4
3 2 9
1 2 4

Sample Output
8
*/
#include<iostream>
#include<vector>
using namespace std;

/*
This question has the exact same approach of max sum non adjascent element but here its min
Storage -> 3 1d Arrays
Meaining -> 
        red[i] = Min cost till ith house with ith house painted red
        blue[i] = Min cost till ith house with ith house painted blue
        green[i] = Min cost till ith house with ith house painted green
Traverse and solve: 
        To paint curr house red, prev house has to be painted either blue or green 
        Same is the case for other two colored houses
*/
int minCost(vector<vector<int>> &vec){
    int red = vec[0][0];
    int blue = vec[0][1];
    int green = vec[0][2];

    for(int i = 0; i < vec.size(); i++){
        int nred = min(blue, green) + vec[i][0];
        int nblue = min(red, green) + vec[i][1];
        int ngreen = min(red, blue) + vec[i][2];

        red = nred;
        blue = nblue;
        green = ngreen;
    }
    return min(red, min(green, blue));
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++)
            cin >> vec[i][j];
    }
    cout << minCost(vec);
}