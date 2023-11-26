
#include <iostream>
using namespace std;

int main(){
    int arr[5]={12,85,65,32,11}, n=5;

    for(int i=0;i<n-1;i++){ //O(n^2)
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        if(i != min_index)
            swap(arr[i], arr[min_index]);
    }

    cout<<"Sorted array : ";
    for(int i=0;i<n;i++)    
        cout<<arr[i]<<" ";
    return 0;
}