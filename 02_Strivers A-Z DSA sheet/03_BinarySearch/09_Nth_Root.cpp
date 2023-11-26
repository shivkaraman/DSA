
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

/*
This is the actual method but pow(mid, n) will be veryy large if m is large so we optimise it further
int power(int x, int y){
    if(y == 0) return 1;

    int XpowNb2 = power(x, y/2);
    if(y%2 == 0)
        return XpowNb2 * XpowNb2;
    else
        return XpowNb2 * XpowNb2 * x;
}

int nthRoot(int n, int m){
    int low = 1, high = m;
    while(low <= high){
        int mid = (low+high)/2;
        int pow = power(mid, n);

        if(pow <= n) 
            low = mid+1;
        else
            high = mid-1;
    }
    return high;
}
*/
int func(int mid, int n, int m) { // here we directly return if pow(mid, n) is >mid or <mid
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);

        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    
    return 0;
}