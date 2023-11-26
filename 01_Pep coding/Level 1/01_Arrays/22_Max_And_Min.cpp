
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[]={1,9,8,6,3},n=5;
    // int Max=INT_MIN, Min=INT_MAX;
    // for(int i=0;i<n;i++){
    //     Max=max(Max,arr[i]);
    //     Min=min(Min,arr[i]);
    // }
    // cout<<"Max : "<<Max<<endl<<"Min : "<<Min<<endl;
    pair<int*,int*> m;
    m = minmax_element(arr,arr+n);
    cout<<"Min : "<<*m.first<<endl<<"Max : "<<*m.second<<endl;
    return 0;
}