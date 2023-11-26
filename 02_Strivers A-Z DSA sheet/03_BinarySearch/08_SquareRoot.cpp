// https://www.youtube.com/watch?v=Bsv3FPUX_BA
//Here wk the range of answers ie WKT the answer is , 1 <= ans <= n so we can apply binary search
// Identification of binary search = ANS RANGE IS KNOWN + FINDING MIN OF MAX 

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

int srareRoot(int n){
    int low = 1, high = n;
    while(low <= high){
        long long mid = (low+high)/2;
        long long square  = mid*mid;

        if(square <= n)
            low = mid+1;
        else if(square > n)
            high = mid-1;
    }
    return high;
}

int main(){
    int n;
    cin >> n;


    return 0;
}