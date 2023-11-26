/*
Given a string s, partition s such that every  substring of the partition is a  palindrome
Return the minimum cuts needed for a palindrome partitioning of s.

https://leetcode.com/problems/palindrome-partitioning-ii/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


bool isPalindrome(string s){
    int n = s.size();
    int oddIdx = n%2 == 0?( -1) : (n+1)/2;
    
    int st = 0, end = n-1;
    while(st < end && s[st] == s[end]){
        st++;
        end--;
    } 

    return st >= end;
}
/*
For each substring substr, it calls the isPalindrome function to check if it is a palindrome. If substr is a palindrome, it updates the prevIdx variable to the index before the current substring.

After checking all possible substrings, it checks the value of prevIdx. 
1. If prevIdx is -2 => No palindrome substring was found
2. If prevIdx is -1, it means the entire string s[0:i] is a palindrome, so no cut is needed. In this case, it sets dp[i] to 0.
3. If prevIdx is neither -2 nor -1, it means there is at least one palindrome substring ending at prevIdx. 
    Eg for case 3 ->  aaabbaaaaaa
        2 options -> {aaa, bb, aaaaaa}, {aaabbaaa, aaa}
    
    Eg 2: abbab
        s = a   b   b   a     b
    dp = 0 | 1 | 1 | 0   | ?
            a | a | a |abba |
            | b | bb|     |

        Now when we try to calculate min cut for the last character 'b', there are 2 possible options 
            {a,b,bab} -> dp[i] = dp[prevIdx] + 1
            {abba, b} -> dp[i] = dp[i-1] + 1
*/
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            int len = i-j+1;
            string substr = s.substr(j, len);
            if(isPalindrome(substr)){
                int prevIdx = i-len;
                dp[i] = prevIdx == -1 ? 0 : min(dp[i], dp[prevIdx]+1);
            }
        }
    }
    return dp[n-1];
}
/*
The above code has a time complexity of O(n^3) => Optimixation is reqired
The extran time of O(N) is because of PALINDROME CHECK => WE need to optimize palindrome check to O(1) which will make the solution O(N^2)

Solution -> We create a 2D array of size N*N -> arr[i][j] will tell if substr(i->j) is palindrome or not
(We condider onlu upper triagle of teh arr cox i the lower triangle starting index > ending index)


A string is palindrom if 
1. Len = 1 => it is palindrome
2. Len = 2 => if first and last char is same
3. Len > 2 => first and last character is same ie s[0]=s[n] and s[1:n-1] is pallindrome

To fill out the 2D array, we have to traverse the arr doagonal wise because travelling diagonal wise allows us to process the stering llength wise
*/

int minCut2(string s) {
    int n = s.size();
    //Is palindrome
    vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));
    int diag = 0;
    while(diag < n){
        int i = 0;
        int j = diag;
        while(i < n && j < n){
            if(i == j)
                isPalindrome[i][j] = true;
            else if(j-i == 1)
                isPalindrome[i][j] = s[i] == s[j];
            else 
                isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);
            i++;
            j++;
        }   
        diag++;
    }
    //Min cut calcuation
    vector<int> dp(n, n);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(isPalindrome[0][i]){
            dp[i] = 0;
            continue;
        } 
        //Exploring all substrings
        for(int j = 0; j <= i; j++){
            if(isPalindrome[j][i] == 1){
                int prevIdx = j-1;
                dp[i] = min(dp[i], dp[prevIdx]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    string s;
    cin >> s;

    std::cout << minCut2(s) << endl;
    return 0;
}
