//Google Kickstart
/*
Isyana is given no of voisitoes  on a local park on n consecutive days. A say is a record braker if 
1. No of visitors on the day is strictly larger than no of visitors onn each of previous days
2. Either it is a last day or the no of visitors is strictly greater than the no of visitors on the next day
*/

#include <iostream>
using namespace std;

int main(){
    int arr[]{1,2,0,7,2,0,2,2}, n=8;
    int record_breaker=0, Max=arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]>Max) && (i==n-1 || arr[i]>arr[i+1]))
            record_breaker++;

        Max=max(Max,arr[i]);
    }
    cout<<"Totoal no of record breaking days : "<<record_breaker<<endl;
    return 0;
}