/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. You are required to calculate and print the count of encodings for the string str.

     For 123 -> there are 3 encodings. abc, aw, lc
     For 993 -> there is 1 encoding. iic 
     For 013 -> This is an invalid input. A string starting with 0 will not be passed.
     For 103 -> there is 1 encoding. jc
     For 303 -> there are 0 encodings. But such a string maybe passed. In this case 
     print 0.
Sample Input
123
Sample Output
3

https://www.youtube.com/watch?v=jFZmBQ569So&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=20
*/

#include<iostream>
#include<vector>
using namespace std;

// Meaning-> dp[i] No of possible encodings for first i digits
// Direction -> 1->n
// Traverse and solve-> For each digit, we have 2 options 
//                      1. To treat it as a single digit and //* append it to all the encodings of i-1
//                      2. If the prevdight and curr digit is <= 26, we can //* append the encoding to all encodings of i-2
int countEncodings(string s){
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1; //* Even though wkt dp[0]=0, we are initializing it to 1 because it is a HELPER value for further indices Eg for i = 1 and str = 103, and option 2 -> dp[idx] += dp[idx-2] ie dp[2] += dp[0] so if we initialize dp[0] = 0, dp[2] will also be 0 which is not the case , so we initialize it to 1
    for(int i = 1; i < s.size(); i++){
        int idx = i+1;
        if(s[i] != '0')
            dp[idx] += dp[idx-1];

        if(s[i-1] != '0'){
            int val = stoi(s.substr(i-1, 2));
            if(val >= 1 && val <= 26){
                dp[idx] += dp[idx-2];
            }
        }
    }
    return dp[n];
}

int main(){
    string s;
    cin >> s;
    cout << countEncodings(s) << endl;
}