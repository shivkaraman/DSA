// Given a 2D array of order n x m with all the elements of rows and columns sorted, search and display the index of target element
/*
Sample Input
    4 
    11 12 13 14
    22 21 23 24
    31 32 33 34
    41 42 43 44
    43
Sample Output
    3
    2
*/
#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int **arr=new int*[m];
    for(int i=0;i<m;i++)
        arr[i]=new int[n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    int target;
    cin>>target;

    bool found=false;
    int r=0,c=m-1;
    while(r<n && c<m){
        if(target<arr[r][c])
            c--;
        else if(target>arr[r][c])
            r++;
        else{
            found=true;
            break;
        }
    }
    if(found)
        cout<<target<<" present at index ["<<r<<" , "<<c<<"]"<<endl;
    else    
        cout<<target<<" not found"<<endl;
    return 0;
}
