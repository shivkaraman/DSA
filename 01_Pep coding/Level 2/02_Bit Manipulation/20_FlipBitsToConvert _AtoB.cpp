/*
1. You are given two numbers A and B.
2. You have to print the count of bits needed to be flipped to convert 'A' to 'B'.

Sample Input
57
76

Sample Output
5

FINAL ANSWER : TOTAL NO OF BITS PRESENNT IN A xor B
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int noOfBits(int n){
    int count = 0;
    while(n != 0){
        int rsb = n & -n;
        n -= rsb;
        count++;
    }
    return count;
}

int flip(int a, int b){
    return noOfBits(a^b);
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << flip(a, b);
    return 0;
}