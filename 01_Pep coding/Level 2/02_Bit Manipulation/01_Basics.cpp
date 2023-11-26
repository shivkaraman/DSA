/*
1. You are given a number n.
2. Print the number produced on setting its i-th bit.
3. Print the number produced on unsetting its j-th bit.
4. Print the number produced on toggling its k-th bit.
5. Also, Check if its m-th bit is on or off. Print 'true' if it is on, otherwise print 'false'.

Sample Input
    57 3  3  3  3
Sample Output
    57
    49
    49
    true
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, k, m;
    cin >> n >> i >> j >> k >> m;

    cout << (n | (1 << i)) << endl;     //Setting ith bit
    cout << (n & (~(1 << j))) << endl;  //Unsetting ith bit
    cout << (n ^ (1 << k)) << endl;     //Toggling ith bit
    cout << (((n & (1 << m)) != 0)? "true" : "false") << endl;
        
}