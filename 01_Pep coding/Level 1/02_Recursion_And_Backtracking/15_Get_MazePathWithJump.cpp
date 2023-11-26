// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner. 
// 3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) 
//     or 1 or more steps diagonally (as d1, d2, ..). 
// 4. Complete the body of getMazePath function
// Sample io
// 2 3
// [h1h1v1, h1v1h1, h1d1, h2v1, v1h1h1, v1h2, d1h1]

#include<iostream>
#include<vector> 

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {  //To get each hpaths one by one and add the paths to mazePath
    if(sr==dr && sc==dc){                                       //  then and there. Same approach for vpath and dpath
        vector<string> base={""}; 
        return base;
    }

    vector<string> mazePaths;

    for(int move = 1; move <= dc - sc; move++){
        vector<string> hpaths = getMazePaths(sr, sc + move, dr, dc);
        for(string hpath: hpaths){
            mazePaths.push_back("h" + to_string(move) + hpath);
        }
    }
        
    for(int move = 1; move <= dr - sr; move++){
        vector<string> vpaths = getMazePaths(sr + move, sc, dr, dc);
        for(string vpath: vpaths){
            mazePaths.push_back("v" + to_string(move) + vpath);
        }
    }
    for(int move = 1; move <= dc - sc && move <= dr - sr; move++){
        vector<string> dpaths = getMazePaths(sr + move, sc + move, dr, dc);
        for(string dpath: dpaths){
            mazePaths.push_back("d" + to_string(move) + dpath);
        }
    }

    return mazePaths;
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