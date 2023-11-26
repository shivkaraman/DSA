/*
1. You are given an array of integers.
2. You are required to test whether the array represents a valid sequence of UTF-8 characters or not.
3. A character in UTF-8 can be from 1 to 4 bytes long and follows some rules - 
       (i)  For 1-byte long character, first bit will be 0 and rest represents its unicode code.
       (ii) For n-bytes long character, first n-bits will be 1's, the n+1th bit is 0, followed by n-1 bytes with most significant 
            2 bits being 10.
1 byte -> 0-------
2 byte -> 110----- 10------ 
3 byte -> 1110---- 10------ 10------ 
3 byte -> 11110--- 10------ 10------ 10------

Sample Input
    3
    197
    130
    1
Sample Output
    true
*/

#include<bits/stdc++.h>
using namespace std;

bool solution(vector<int>& arr){
    int rbytes = 0; //remaining bytes
    for (int val : arr) {
        if(rbytes == 0) {
            if ((val >> 7) == 0b0) // 1 length/byte char
                rbytes = 0 ;
            else if ((val >> 5) == 0b110) // 1st byte of 2 length/byte char
                rbytes = 1 ;
            else if ((val >> 4) == 0b1110)// 1st byte of 3 length/byte char
                rbytes = 2 ;
            else if (( val >> 3) == 0b11110)// 1st byte of 4 length/byte char
                rbytes = 3 ;
            else
                return false;
        } 
        else{
            if((val >> 6) == 0b10)
                rbytes--;
            else
                return false;
        }
    }
    return (rbytes == 0);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin>>arr[i];
    
    if(solution(arr))
        cout << "true";
    else
        cout << "false";
}