/*
1. You are given an array of n numbers.
2. You have to find the sum of bit differences in all pairs that can be formed from n numbers.
3. Bit difference of two numbers is defined as the count of different bits at same positions in binary representations of two numbers.

Sample Input
    3
    1 2 3
Sample Output
    8
*/


#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> vec){
     int ans = 0;
    for(int i = 0; i < 32; i++){
        int  countOn = 0;
        for(int &val : vec){
            if(val & (1 << i) != 0)
                countOn++;
        }
        int countOff = vec.size() - countOn;
        ans += (countOff * countOn * 2);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++)
        cin >> vec[i];

   
    return 0;
}