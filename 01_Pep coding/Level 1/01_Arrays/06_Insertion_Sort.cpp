
#include <iostream>
using namespace std;

int main(){
    int arr[5]={12,85,65,32,11}, n=5;

    for(int i=1;i<n;i++){ //O(n^2)
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    cout<<"Sorted array : ";
    for(int i=0;i<n;i++)    
        cout<<arr[i]<<" ";
    return 0;
} 