
#include <iostream>
using namespace std;

int main(){
    int arr[]={12,56,25,36,10},element;
    cout<<"Enter the element to be searched : ";
    cin>>element;

    for(int i=0;i<5;i++){   //O(n)
        if(arr[i] == element){
            cout<<element<<" is found at index "<<i<<endl;
            exit(0);
        }
    }
    cout<<"Element not found "<<endl;
    return 0;
}