// https://leetcode.com/problems/count-good-numbers/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#define MOD 1000000007
using namespace std;

/*
For any given n there are 
    (n+1)/2 even indices and 
    n/2 odd indices and 

No of even nos between 0 and 9 is 5 [0,2,4,6,8]
No of prime nos between 0 and 9 is 5 [2,3,5,7]

Hence no of good nos that can be generated from n digits is [5 ^ (n+1)/2]*[4 ^ n/2]
*/
#define MOD 1000000007
class Solution {
public:
    long long myPow(int x, long long n) {
        if(n == 0) return 1;
        else if(n == 1) return x;

        long long xpnb2 = myPow(x, n/2);

        if(n%2 == 0)
            return (xpnb2 * xpnb2)%MOD;
        else
            return (xpnb2 * xpnb2 * x)%MOD;
    }
    
    int countGoodNumbers(long long n) {
        long long evenInd = (n+1)/2;
        long long oddInd = n/2;

        long long first = myPow(5, evenInd)%MOD;
        long long second = myPow(4, oddInd)%MOD;
        return (int)((first * second)%MOD);
    }
};
int main(){
    
    return 0;
}