//Amazon, Samsung, Snapdeal, Accenture
// Given an array of n integers, find the smallest missing positive integer

#include <iostream>
using namespace std;

int main(){
    int arr[]={0,-9,5,1,3}, n=5;
    int N=1e6+2;
    bool check[N];

    for(int i=0;i<N;i++)
        check[i]=false;
    
    for(int i=0;i<n;i++){
        if(arr[i]>=0)
            check[arr[i]]=true;
    }

    for(int i=0;i<N;i++){   
        if(check[i]==false){
            cout<<"Smallest missing positive integer : "<<i<<endl;
            break;
        }
    }
    return 0;
}