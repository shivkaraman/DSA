// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. The two arrays represent digits of two numbers.
// 6. You are required to find the difference of two numbers represented by two arrays and print the arrays. a2 - a1

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
    
    int *diff= new int[n2];
    int i=n1-1;
    int j=n2-1;
    int x=j;
    int carry=0;
    while(j>=0){
        int d=carry;        
        if(i>=0){
            if(a2[j]-a1[i]<0){
                d+=10+a2[j]-a1[i];
                carry=-1;
            }
            else{
                d+=a2[j]-a1[i];
                carry=0;
            }
        }
        else{
            d+=a2[j];
            carry=0;
        }
        diff[j]=d;
        i--;
        j--;
    }
    for(int i=0;i<=x;i++)
        cout<<diff[i];
    return 0;
}

