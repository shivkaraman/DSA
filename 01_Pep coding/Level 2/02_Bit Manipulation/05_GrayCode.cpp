/*
1. The gray code is a binary numeral system where two successive numbers differ in only one bit.
2. Given a non-negative integer n representing the total number of bits in the code, print the 
     sequence of gray code. A gray code sequence must begin with 0.

Input: 2
Output: 
[0,1,3,2]
    Explanation:
    00 - 0
    01 - 1
    11 - 3
    10 - 2

[0,2,3,1] is also a valid gray code sequence.
    00 - 0
    10 - 2
    11 - 3
    01 - 1

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Expectation - give me gray code of n
//Faith - function already knows to find gray code of n-1 
//E-F - prepend 0 or 1 to gray code of n-1 to get gray code of n
vector<string> grayCode(int n){
    if(n == 0){
        return {"0"};
    }
    if(n == 1){
        vector<string> vec{"0", "1"};
        return vec;
    }
    vector<string> nm1 = grayCode(n-1);
    vector<string> gray;
    for(string s : nm1){
        gray.push_back("0" + s);
    }
    for(int i = nm1.size()-1; i >= 0; i--){
        gray.push_back("1" + nm1[i]);
    }
    return gray;
}

vector<int> binToDec(vector<string> vec){
    vector<int> gray;
    for(string s : vec){
        int powOf2 = 1;
        int temp = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '0')
                temp += powOf2 * 0;
            else
                temp += powOf2 * 1;
            powOf2 *= 2;
        }
        gray.push_back(temp);
    }
    return gray;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<string> res = grayCode(n);
    vector<int> gray = binToDec(res);
    cout << "[";
    for(int i = 0; i < gray.size(); i++){
        cout << gray[i];
        if(i != gray.size()-1)  
            cout << ", ";
    }
    cout << "]";
}