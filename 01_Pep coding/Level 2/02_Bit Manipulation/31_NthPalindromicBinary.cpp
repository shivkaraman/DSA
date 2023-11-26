/*
1. You are given an integer N.
2. You have to find the N-th number whose binary representation is a palindrome.
Note -> First binary number whose representation is a palindrome is 1.
 
Sample Input
    17
Sample Output
    85  

lenght  No of palindrome
    1       1
    2       1

    3       2
    4       2

    5       4
    6       4

    7       8
    8       8

No of palindromes for given length = 2^{(l-1)/2}
but we need to find length for given n
Explanation : 
    Say length = 7
        then palindrome is of the form : abcdcba
        a -> must be 1
        bc -> can be 0/1
        d -> can be 0/1
        abcdcba : 1_ _ d * * 1
    Therefore no of palindromes possible = 2^3 = 8 = 2^{(l-1)/2}
    we need the offset = ie what is bcd to find the actual palindrome
                       
if we find length and offset the palindrome is : 1 (offset in binary) (reverse of ffset in binary) 1

*/

#include<iostream>
using namespace std;

int reverseBits(int n){
    int rev = 0;
    while(n){
        int bit0 = (n & 1);
        rev |= bit0;
        n >>= 1;
        rev <<= 1;
    }
    rev >>= 1;
    return rev;
}

int NthPalindromicBinary(int n){
    //FINDING OFFSET AND LENGTH
    int count = 1, len = 1;
    while(count < n){
        len++;
        int noOfEle = (1 << ((len-1)/2)); //No of palindromes for this length
        count += noOfEle;
    }
    count -= (1 << ((len-1)/2)); //We exited loop coz we exceeded n, so we need to get back
    int offset = n-count-1;

    //CREATING BINARY PALINDROME
    int leftHalf = (1 << (len-1));
    leftHalf |= (offset << (len/2));

    int rightHalf = (leftHalf >> (len/2));
    rightHalf = reverseBits(rightHalf);

    int palindrome = leftHalf | rightHalf;
    return palindrome;
}

int main(){
    int n;
    cin >> n;

    int ans = NthPalindromicBinary(n);
    cout << ans << endl;
    return 0;
}