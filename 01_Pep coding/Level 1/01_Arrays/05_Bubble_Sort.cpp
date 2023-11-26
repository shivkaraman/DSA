
#include <iostream>
using namespace std;

int main(){
    int arr[5]={12,85,65,32,11}, n=5;
    for(int i=0;i<n-1;i++){ //O(n^2)
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }

    cout<<"Sorted array : ";
    for(int i=0;i<n;i++)    
        cout<<arr[i]<<" ";
    return 0;
}