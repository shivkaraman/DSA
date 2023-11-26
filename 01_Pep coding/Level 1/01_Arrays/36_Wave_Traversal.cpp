// 1. You will be given a number n, representing the number of rows.
// 2. You will be given a number m, representing the number of columns.
// 3. You will be given n*m numbers, representing elements of 2d arrays.

// 1  2  3
// 4  5  6
// 7  8  9

// Path followed by traveler: 1->4->7->8->5->2->3->6->9

#include <iostream>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;

    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cin>>arr[i][j];
    }
    
    int rs= 0, re=r-1, cs=0, ce=c-1,x=0;
    // row start, row end, column start, column end
    for(;cs<=ce;cs++){
        if(cs%2==0){
            for(int i=0;i<=re;i++) 
                cout<<arr[i][cs]<<endl;
        }
        else{
            for(int i=re;i>=0;i--)
                cout<<arr[i][cs]<<endl;
        }
    }
    return 0;
}