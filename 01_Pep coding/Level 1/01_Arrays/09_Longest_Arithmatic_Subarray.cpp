//Google-Kickstart
//Arithmatic subarray --> Sub-array whose elements are in an AP 

#include <iostream>
using namespace std;

int main(){
    int arr[]={10,7,4,6,8,10,11},n=7;
    int curr_len=2;
    int max_len=2;
    int pd = arr[1]-arr[0];
    for(int i=2;i<n;i++){   //O(n)
        if(pd == arr[i]-arr[i-1])
            curr_len++;
        else{
            pd = arr[i]-arr[i-1];
            curr_len = 2;
        }
        max_len = max(curr_len,max_len);
    }
    cout<<"Max length of arithmatic subarray : "<<max_len<<endl;
    return 0;
};
