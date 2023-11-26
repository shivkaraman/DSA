
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

int countSubStrings(string str, int k) {
    unordered_map<char, int> mpk, mpkm1;
    int ik = 0, ikm1 = 0, j = 0;
    int ans = 0;
    while(true){
        bool f1 = false, f2 = false, f3 = false;
        while(ik < str.size()){
            f1 = true;
            char ch = str[ik];
            if(mpk.find(ch) == mpk.end() && mpk.size() == k) break;
            mpk[ch]++;
            ik++;
        }
        while(ikm1 < str.size()){
            f2 = true;
            char ch = str[ikm1];
            if(mpkm1.find(ch) == mpkm1.end() && mpkm1.size() == k-1) break;
            mpkm1[ch]++;
            ikm1++;
        }
        while(j < ikm1){
            f3 = true;
            char ch = str[j++];
            ans += ik - ikm1;

            if(mpk[ch] == 1) mpk.erase(ch);
            else mpk[ch]--;

            if(mpkm1[ch] == 1)mpkm1.erase(ch);
            else mpkm1[ch]--;

            if(mpk.size() != k || mpkm1.size() != k-1) break;
        }
        if(!f1 && !f2 && !f3) break;
    }
    return ans;
}


int main(){
    cout << countSubStrings("abcab", 2);
    return 0;
}