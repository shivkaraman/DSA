/*
You have been given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps (0 to infinite) in order to make it a palindromic string.

Sample Input
    3242415
Sample Output
    5

https://www.youtube.com/watch?v=rZPCi5JySY4
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longestAwesome(string str){
    unordered_map<int, int> mp; //map(mask, index)
    int mask = 0, count = 0;
    mp[0] = -1;
    for(int i = 0; i < str.size(); i++){
        int num = str[i] - '0';
        mask ^= (1 << num);
        if(mp.find(mask) != mp.end())
            count = max(count, i-mp[mask]);

        for(int d = 0; d <= 9; d++){
            int tempMask = (mask ^ (1 << d));
            if(mp.find(tempMask) != mp.end())
                count = max(count, i-mp[mask]);
        }
        if(mp.find(mask) == mp.end())
            mp[mask] = i;
    }
    return count;
}

int main(){
    string str;
    cin >> str;

    cout << longestAwesome(str) << endl;
    return 0;
}