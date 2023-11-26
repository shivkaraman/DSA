// 1. You are given a number n, representing the number of rows and number of columns.
// 2. You are given n*n numbers, representing elements of 2d array a.
// 3. You are required to rotate the matrix by 90 degree clockwise and then display the contents using display function.
/*
-ve implies clockwise 
We know hoe to rotate a 1D array
We can feed all the elements of the shell in 1D array , rotate it and again feed it into shell
*/

#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int *a ,int s ,int e){
    while(s<e){
        swap(a[s],a[e]);
        s++;
        e--;
    }
}

void rotate(int *a,int size, int k){
    reverse(a,size-k,size-1);
    reverse(a,0,size-k-1);
    reverse(a,0,size-1);
}

int main(){
    int r,c;
    cin>>r>>c;

    int **arr = new int*[r];
    for(int i=0;i<r;i++)
        arr[i] = new int[c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cin>>arr[i][j];
    }

    int s,k;
    cin>>s>>k;

    int rs = s-1 ,re = r-s ,cs = s-1 ,ce = c-s,i=0,idx; 
    int size = 2*(re-rs+1 + ce-cs+1)-4;
    int *oned = new int[size];

    //Shell to 1D array
    for(idx=rs;idx<=re;idx++,i++)
        oned[i] = arr[idx][cs];

    for(idx=cs+1;idx<=ce;idx++,i++)
        oned[i] = arr[re][idx];
    
    for(idx=re-1;idx>=rs;idx--,i++)
        oned[i] = arr[idx][ce];
    
    for(idx=ce-1;idx>cs;idx--,i++)
        oned[i] = arr[rs][idx];

    //Rotate 1d array
    k = k%size;
    if(k<0)     
        k=size+k;
    rotate(oned,size,k);

    //1D array to Shell
    i=0;
    for(idx=rs;idx<=re;idx++,i++)
        arr[idx][cs] = oned[i];

    for(idx=cs+1;idx<=ce;idx++,i++)
        arr[re][idx] = oned[i];
    
    for(idx=re-1;idx>=rs;idx--,i++)
        arr[idx][ce] = oned[i];
    
    for(idx=ce-1;idx>cs;idx--,i++)
        arr[rs][idx] = oned[i];
    

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}