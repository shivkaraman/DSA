// https://leetcode.com/problems/2-keys-keyboard/
// https://www.youtube.com/watch?v=anHoebBokmg&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=7  

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int n){
    int ans = 0;
    for(int i = 2; i*i <= n; ){
        if(n%i == 0){ //=> i is a factor of n 
            ans += i;
            n /= i;
        }
        else{
            i++;
        }
    }
    if(n != 1) ans += n;
    return ans;
}

int main(){
    int n;
    cin >> n;

    cout << solution(n);
    return 0;
}