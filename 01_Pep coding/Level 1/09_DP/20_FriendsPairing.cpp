/*
1. You are given a number n, representing the number of friends.
2. Each friend can stay single or pair up with any of it's friends.
3. You are required to print the number of ways in which these friends can stay single or pair up.

E.g.
1 person can stay single or pair up in 1 way.
2 people can stay singles or pair up in 2 ways. 12 => 1-2, 12.
3 people (123) can stay singles or pair up in 4 ways. 123 => 1-2-3, 12-3, 13-2, 1-23.

Sample Input
4

Sample Output
10
*/
#include <iostream>
#include <vector>
using namespace std ;

/*
for n = 4 ie 1234
1 can either be single or pair up with 2 or 3 or 4 
Single -> 1 can append to pairings(234) which is nothing but dp[i] = dp[i-1]
Pairint-> 12 can append to pairings(34) which is nothing but dp[i-2]   |
          13 can append to pairings(24) which is nothing but dp[i-2]   |=> (i-1)*dp[i-2]
          14 can append to pairings(23) which is nothing but dp[i-2]   |

https://www.youtube.com/watch?v=SHDu0Ufjyk8&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=28
*/
int friendsPairing(int n){
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        int single = dp[i-1]; //Curr element can stay single and attach to all pairings of i-1
        int paired = (i-1) * dp[i-2]; //Curr element can pair up with any of the other i-1 elements , so remaining elements is i-2 now. The current pair can attack to all the pairings of i-2
        dp[i] = single + paired;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << friendsPairing(n);
    return 0;
}