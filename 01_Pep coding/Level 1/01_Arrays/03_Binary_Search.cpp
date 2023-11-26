
#include <iostream>
using namespace std;

int main(){
    int arr[]={26,86,125,885,1022},element;
    cout<<"Enter the element to be searched : ";
    cin>>element;

    int s=0, e=4;

    while(s <= e){      //O(log n)
        int mid=(s+e)/2.0;
        if(arr[mid]==element){
            cout<<element<<" found at index "<<mid<<endl;
            exit(0);
        }

        else if( element > arr[mid])
            s=mid+1;

        else
            e=mid-1;
    }
    cout<<"Element not found"<<endl;
    return 0;
}