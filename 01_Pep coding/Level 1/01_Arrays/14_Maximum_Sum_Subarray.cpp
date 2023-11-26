//Kadanes Algorithm

#include <iostream>
using namespace std;

int main(){
    int arr[] = {-1,3,5,-2,8,4,6,-2}, n = 8;
    int currSum=0, maxSum=0;

    for(int i=0;i<n;i++){   //O(n)
        if(arr[i]>0)
            currSum+=arr[i];
        else
            currSum=0;

        maxSum=max(currSum, maxSum);
    }
    cout<<"Max sum : "<<maxSum<<endl;
    return 0;
} 