// https://leetcode.com/problems/powx-n/description/

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
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        else if(n == 1) return x;
        else if(n == -1) return 1/x;

        double xpnb2 = myPow(x, n/2);
        return n%2 == 0 ? xpnb2 * xpnb2 : (n < 0 ? xpnb2 * xpnb2 * 1/x : xpnb2 * xpnb2 * x);
    }
};

int main(){
    
    return 0;
}