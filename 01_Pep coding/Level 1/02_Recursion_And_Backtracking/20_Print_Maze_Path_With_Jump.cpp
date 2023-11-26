
#include<iostream>
using namespace std;

//level -> current position in maze
//option-> how much spets to take and in which direction
void printMazePaths(int sr, int sc, int dr, int dc, string mp) {
    if(sr==dr && sc==dc){
        cout<<mp<<endl;
        return;
    }

    if(sr>dr || sc>dc)
        return;

    for(int i=1;i<=dc-sc;i++)
        printMazePaths(sr,sc+i,dr,dc,mp+"h"+to_string(i));
    
    for(int i=1;i<=dr-sr;i++)
        printMazePaths(sr+i,sc,dr,dc,mp+"v"+to_string(i));
    
    for(int i=1;i<=dr-sr && i<=dc-sc;i++)
        printMazePaths(sr+i,sc+i,dr,dc,mp+"d"+to_string(i));
        
}

int main() {
    int n ;
    int m ;
    cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
