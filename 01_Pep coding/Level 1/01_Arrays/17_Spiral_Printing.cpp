
#include <iostream>
using namespace std;

int main(){
    int matrix[5][6]={1,  5,  7,  9,  10, 11,
                      6,  10, 12, 13, 20, 21,
                      9,  25, 29, 30, 32, 41,
                      15, 55, 59, 63, 68, 70,
                      40, 70, 79, 81, 95, 105 };
    int n=5, m=6; 
    int rs= 0, re=n-1, cs=0, ce=m-1;
    // row start, row end, column start, column end
    while(rs<=re && cs<=ce){
        for(int j=cs;j<=ce;j++)
            cout<<matrix[rs][j]<<" ";
        rs++;
        
        for(int i=rs;i<=re;i++)
            cout<<matrix[i][ce]<<" ";
        ce--;

        for(int j=ce;j>=cs;j--)
            cout<<matrix[re][j]<<" ";
        re--;

        for(int i=re;i>=rs;i--)
            cout<<matrix[i][cs]<<" ";
        cs++;
    }
    return 0;
}