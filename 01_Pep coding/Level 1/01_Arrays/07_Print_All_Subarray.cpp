//Output all subarrays of a given array

#include <iostream>
using namespace std;

int main(){
    int arr[]={1,2,0,7,2},n=5;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++)
                cout<<arr[k]<<" ";
            cout<<endl;
        }
    }
    return 0;
}