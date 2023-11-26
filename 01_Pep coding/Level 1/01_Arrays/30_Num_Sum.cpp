/*
1. You are given a number n1, representing the size of array a1.
2. You are given n1 numbers, representing elements of array a1.
3. You are given a number n2, representing the size of array a2.
4. You are given n2 numbers, representing elements of array a2.
5. The two arrays represent digits of two numbers.
6. You are required to add the numbers represented by two arrays and print the arrays.
 
    carry ->    1 1
    a1    ->    9 9 9
    a2    ->    1 1 1
    sum   ->  1 1 1 0

*/

#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1;

    int* a1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>a1[i];
    }
    
    cin>>n2;

    int* a2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>a2[i];
    }
    
    int *sum= new int[max(n1,n2)+1];
    int i=n1-1;
    int j=n2-1;
    int k=max(n1,n2);
    int x=k;
    int carry = 0;
    while(k>=0){
        int s=carry;
        if(i>=0){
            s+=a1[i];
            i--;
        }
        if(j>=0){
            s+=a2[j];
            j--;
        }

        sum[k]=s%10;
        carry=s/10;
        k--;
    }
    for(int i=0;i<=x;i++)
        cout<<sum[i];
    return 0;
}