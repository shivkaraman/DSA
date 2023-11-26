/*
Given a string s, partition s such that every  substring of the partition is a  palindrome
Return the minimum cuts needed for a palindrome partitioning of s.

https://leetcode.com/problems/palindrome-partitioning-ii/
*/
#include <iostream>
#include <vector>
using namespace std;

int minCut(string s) { //O(N^3)
    int n = s.size();
    // Is palindrome
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false)); 
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; i < n && j < n; i++, j++) {
            if (g == 0)
                isPalindrome[i][j] = true;
            else if (g == 1)
                isPalindrome[i][j] = (s[i] == s[j]);
            else
                isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
        }
    }

    // Min cut calculation
    vector<vector<int>> dp(n, vector<int>(n, n));
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; i < n && j < n; i++, j++) {
            if (isPalindrome[i][j])
                dp[i][j] = 0;
            else {
                for (int k = i; k < j; k++) {
                    int left = dp[i][k];
                    int right = dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], left + right + 1);
                }
            }
        }
    }
    return dp[0][n - 1];
}

// Optimization -> Same code as we saw in the previous optmization approach
// Approach -> We have to make a cut only when we encounter  a palindrome and not after every character
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
    vector<int> dp(n, n);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(isPalindrome[0][i]){ // If substring[0->i] is palindrome we need 0 cuts
            dp[i] = 0;
            continue;
        }
        //Cutting only when substr[j,i] is a palindrome
        for(int j = i; j >= 0; j--){ 
            if(isPalindrome[j][i])
                dp[i] = min(dp[i], dp[j-1]+1);
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
