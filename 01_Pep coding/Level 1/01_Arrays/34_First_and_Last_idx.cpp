// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a ( Array is sorted. Array may have duplicate values)
// 3. You are given another number whose first and last index is to be found

// 15
// 1 5 10 15 22 33 33 33 33 33 40 42 55 66 77 
// 33

//Op-> 5 9

#include <iostream>
#include <climits>
using namespace std;

int binary(int arr[],int element,int s,int e,bool flag){
    int idx;
    while(s <= e){      //O(log n)
        int mid=(s+e)/2.0;
        if(arr[mid]==element){
            if(flag)         //Last index
                s=mid+1;  
            else if (!flag)  //First index 
                e=mid-1;
            idx=mid;   
        }
        else if( element > arr[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return idx;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int element;
    cin>>element;

    int s=0, e=n-1,i1=-1,i2=-2;
    i2=binary(arr,element,s,e,1);   //To find the last index
    i1=binary(arr,element,s,e,0);   //To find the first index
    cout<<i1<<endl<<i2;
    return 0;
} 