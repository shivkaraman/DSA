//Given a sorted array of n elements and sum , find the pair of elements which sum up to given sum

#include <iostream>
using namespace std;

int main(){
    int arr[]={2,4,7,11,14,16,20,21},n=8;   //Array must be sorted
    int sum=31;
    int s=0,e=n-1;
    while(s<e){
        if((arr[s]+arr[e])>sum)
            e--;
        else if((arr[s]+arr[e])<sum)
            s++;
        else{
            cout<<"Pair : "<<s<<" , "<<e<<endl;
            break;
        }
    }
    cout<<"Pair sum not found"<<endl;
    return 0;
}