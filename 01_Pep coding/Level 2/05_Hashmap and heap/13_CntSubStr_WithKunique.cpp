// https://nados.io/question/count-of-substrings-with-exactly-k-unique-characters?zen=true
// https://www.youtube.com/watch?v=CBSeilNvZHs&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=13

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;

int solFor1(string s){
    // map<char, freq>
    unordered_map<char, int> mp;
    int i = 0, j  = 0;
    int ans = 0, unique = 0;
    int k = 1;
    while(true){
        bool flag1 = 0, flag2 = 0;
        //Acquire till unique == k
        while(i < s.size()){
            flag1 = true;
            char ch = s[i];
            if(mp.find(ch) == mp.end()) unique++; 
            if(unique > k) break;
            mp[ch]++;
            i++;
        }
        unique--;
        //Release till one unique element is removed 
        while(j < i){
            flag2 = true;
            //Collect ans
            ans += i-j;

            char ch = s[j++];//j is incrimented intensionally here coz say if unique element is removed and we break, we need to point to next element of uniquw
            if(mp[ch] == 1){
                mp.erase(ch);
                unique--;
                break;
            }   
            else mp[ch]--;          
        }
        if(!flag1 && !flag2) break;
    }
    return ans;
}

int solution(string s, int k){
    // map<char, freq>
    if(k == 1) return solFor1(s);

    unordered_map<char, int> mpK;       //Unique = k
    unordered_map<char, int> mpKm1;     //unique = k-1
    int iK = 0;                //Indices for mpK
    int iKm1 = 0;              //Indices form mpKm1
    int j = 0;
    int count = 0, uniqueK = 0, uniqueKm1 = 0;
    while(true){
        //Acquiring in mpK -> Acquire till unique == k
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        while(iK < s.size()){
            flag1 = true;
            char ch = s[iK];
            if(mpK.find(ch) == mpK.end()) uniqueK++; 
            if(uniqueK > k) break;
            mpK[ch]++;
            iK++;
        }
        uniqueK--;

        //Acquiring in mpKm1 -> Acquire till unique == k-1
        while(iKm1 < iK){
            flag2 = true;
            char ch = s[iKm1];
            if(mpKm1.find(ch) == mpKm1.end()) uniqueKm1++; 
            if(uniqueKm1 > k-1) break;
            mpKm1[ch]++;
            iKm1++;
        }
        uniqueKm1--; 
        //Releasing in both until unique char is removed in any of the maps
        while(j < iKm1){
            flag3 = true;
            //Collecting ans
            count += iK - iKm1;

            char ch = s[j++];
            if(mpKm1[ch] == 1){
                mpKm1.erase(ch);
                uniqueKm1--;
            }
            else mpKm1[ch]--;

            if(mpK[ch] == 1){
                mpK.erase(ch);
                uniqueK--;
            }
            else mpK[ch]--;

            if(uniqueK != k || uniqueKm1 != k-1) break;
        }
        //Loop break contition
        if(!flag1 && !flag2 && !flag3) break;
    }
    return count;
}

int main(int argc,char** argv){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout<< solution(s, k) << endl;
}