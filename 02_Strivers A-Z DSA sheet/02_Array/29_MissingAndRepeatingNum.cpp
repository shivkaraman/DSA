
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

vector<int> findMissingRepeatingNumbers(vector<int> arr){ //T=O(n) S=O(n)
    int n = arr.size();
    vector<bool> visited(n+1, false);

    int missingEle = -1, repeatingEle = -1;
    for(int i = 0; i < n; i++){
        if(visited[arr[i]] == true){
            repeatingEle = arr[i];
        }
        visited[arr[i]] = true;
    }

    for(int i = 1; i <= n; i++){
        if (visited[i] == false) {
            missingEle = i;
            break;
        }
    }
    return vector<int>{repeatingEle, missingEle};
}
/*
sn = sum of first n numbers
s2n =  sum of squares of first n numbers

s = sum of all array elements
s2 = sum of squares of all array elements

for array [4 3 6 2 1 1], repeating element (X) = 1 and missing num(Y) = 5
1.  sn = 1+2+3+4+5+6
    s  = 4+3+6+2+1+1

    s-sn = 1-5 = -4
    => X-Y = -4

2.  s2n = 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2
    s2 = 4^2 + 3^2 + 6^2 + 2^2 + 1^2 + 1^2

    s2-s2n = 1^2 - 5^2 = -24
    X^2 - Y^2 = -24
    (X+Y) (X-Y) = -24
    (X+Y) = -24/ (X-Y)
    X+Y = -24/-4
    X+Y = 6

By solving the above two equations, we can get X and Y

*/
vector<int> findMissingRepeatingNumbers2(vector<int> arr){
    long long n = arr.size();

    long long sn = n * (n+1) / 2;
    long long s2n = n * (n+1) * (2*n+1) / 6;

    long long s=0, s2 = 0;
    for(int i = 0; i < n; i++){
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s - sn;   //X-Y
    long long val2 = s2 - s2n; //(X+Y) (X-Y)
    val2 /= val1;        //X+Y

    long long X = (val1 + val2) / 2;
    long long Y = val2 - X;

    return {(int)X, (int)Y};
}

int main(){
    
    return 0;
}