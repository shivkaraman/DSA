/*
Sample Input
    4
    1 1 1 2 
Sample Output
    2
*/
#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>& arr){
    //If tehre are -ve numbers in array, initialise 3n to -1 which ensures the all the 32 bits in 3n are ON but in INTMAX MSB is 0
    int tn = INT_MAX, tnp1 = 0, tnp2 = 0; //3n, 3n+1, 3n+2
    for(int i = 0; i < arr.size(); i++){
        int cwtn = arr[i] &  tn;    //Common with 3n     
        int cwtnp1 = arr[i] & tnp1; //Common with 3n+1
        int cwtnp2 = arr[i] & tnp2; //Common with 3n+2

        //Common with 3n -> Turn these bits off in 3n and turn them on in 3n+1
        tn = tn & (~cwtn);
        tnp1 = tnp1 | cwtn;

        //Common with 3n+1 -> Turn these bits off in 3n+1 and turn them on in 3n+2
        tnp1 = tnp1 & (~cwtnp1);
        tnp2 = tnp2 | cwtnp1;

        //Common with 3n -> Turn these bits off in 3n+2 and turn them on in 3n
        tnp2 = tnp2 & (~cwtnp2);
        tn = tn | cwtnp2;
    }
    return tnp1;
}


int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<solution(arr);
}