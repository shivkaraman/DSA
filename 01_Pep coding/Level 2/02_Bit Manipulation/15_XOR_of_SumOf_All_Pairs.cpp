/*
1. You are given an array of integers.
2. You have to find the XOR of sum of all pairs in the array.

Sample Input
    5 
    1 5 2 1 2
Sample Output
    10
*/
#include<bits/stdc++.h>
using namespace std;
/*
for an array a b c d
pairs -> 
a+a  b+a  c+a d+a
a+b  b+b  c+b d+b
a+c  b+c  c+c d+c
a+d  b+d  c+d d+d

XOR of sum of pairs -> a+b cancels out with b+a, similarly all pairs cancels out each other
Left out ones are 2a  2b  2c  2d
*/
int solution(vector<int> &v1){
    int XOR = 0;
    for(int x : v1)
        XOR ^= (2*x);
    return XOR;
}

int main(){
    int n;
    cin>>n;

    vector<int> v1(n);
    for(int i=0;i<n;++i) 
        cin>>v1[i];

    cout<<solution(v1)<<"\n";
    return 0;
}