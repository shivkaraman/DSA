//Maximum sum circular subarray

#include <iostream>
using namespace std;

int kadane(int arr[], int n){
    int currSum=0; 
    int maxSum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            currSum+=arr[i];
        else        
            currSum=0;
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}

int main(){
    int arr[]={4,-4,6,-6,10,-11,12},n=7;
    int total_sum=0, nowrapSum=0, wrapSum=0;

    for(int i=0; i<n;i++)
        total_sum += arr[i];

    nowrapSum=kadane(arr,n);
    
    for(int i=0;i<n;i++)
        arr[i]= -arr[i];
    
    wrapSum= total_sum + kadane(arr,n);

    int max_sum =  max(nowrapSum, wrapSum);
    cout<<"Max Sum = "<<max_sum<<endl;
    return 0;
}