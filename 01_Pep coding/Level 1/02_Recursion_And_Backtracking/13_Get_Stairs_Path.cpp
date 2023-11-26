// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
// 3. Complete the body of getStairPaths function
// Sample Input
//  3
// Sample Output
// [111, 12, 21, 3]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getStairPaths(int n){
    if(n==0){
        vector <string> base={""};
        return base;
    }
    else if(n<0){
        vector <string> base;
        return base;
    }
    vector<string> p1 = getStairPaths(n-1);
    vector<string> p2 = getStairPaths(n-2);
    vector<string> p3 = getStairPaths(n-3);

    vector <string> paths;
    for(string &str : p1)
        paths.push_back("1"+ str);

    for(string &str : p2)
        paths.push_back("2"+ str);

    for(string &str : p3)
        paths.push_back("3"+ str);
    
    return paths;
}

int main(){
    int n;
    cin>>n;

    vector<string> paths = getStairPaths(n);
    int cnt=0;
    cout << '[';
    for (string &str : paths){
        if (cnt != paths.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}
