// https://www.youtube.com/watch?v=NNBQik4phMI&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=23

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class solution{
    public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<map<char, int>, vector<string>> mp;
        for(string &s : strings){
            map<char, int> freqmp;
            for(char ch : s){
                freqmp[ch]++;
            }
            mp[freqmp].push_back(s);
        }   
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> string_list(n);
    for(int i = 0; i < n; i++){
        cin >> string_list[i];
    }
    
    solution ob;
    vector<vector<string>> res = ob.groupStrings(string_list);
    
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}