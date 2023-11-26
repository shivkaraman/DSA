
#include <iostream>
using namespace std;

//level -> current sposition in maze
//option-> to take hoeizontal or vertical step
void printMazePaths(int sr, int sc, int dr, int dc, string mp){
    // write your code here
    if(sr==dr && sc==dc){
        cout<<mp<<endl;
        return;
    }
    if(sr>dr || sc>dc)
        return;
    if(sc<dc)
        printMazePaths(sr,sc+1,dr,dc,mp+"h");
    if(sr<dr)
        printMazePaths(sr+1,sc,dr,dc,mp+"v");
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}