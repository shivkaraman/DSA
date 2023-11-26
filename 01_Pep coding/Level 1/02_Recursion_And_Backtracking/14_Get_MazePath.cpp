// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' 
//   (1-step horizontal) and 'v' (1-step vertical).
// 3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.
// Sample Input
//  3 3
// Sample Output
// [hhvv, hvhv, hvvh, vhhv, vhvh, vvhh]

#include<iostream>
#include<vector> 
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr==dr && sc==dc){
        vector<string> base={""};
        return base;
    }
    vector <string> hpath;
    vector <string> vpath;
    if(sr<dr)
        vpath = getMazePaths(sr+1,sc,dr,dc); 
    if(sc<dc)
        hpath = getMazePaths(sr,sc+1,dr,dc); 
        
    vector<string> maizePath;
    for(string &str : hpath)
        maizePath.push_back("h"+str);
        
    for(string &str : vpath)
        maizePath.push_back("v"+str);
    return maizePath;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) 
            cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; 
    cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}