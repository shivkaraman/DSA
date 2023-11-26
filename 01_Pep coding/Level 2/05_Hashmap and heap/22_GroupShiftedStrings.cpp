// https://nados.io/question/group-shifted-string
// https://www.youtube.com/watch?v=uEXJSRLqoKY&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=24

#include <bits/stdc++.h>

using namespace std;

class solution{
    public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for(string &s : strings){
            string diff = "";
            for(int i = 1; i < s.length(); i++){
                int x = s[i] - s[i-1];
                if(x < 0) x += 26;
                diff += to_string(x);
            }
            mp[diff].push_back(s);
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
        sort(res[i].begin(),res[i].end());
    }
    
    sort(res.begin(), res.end(),[&](vector<string> a,vector<string> b){
        if(a.size()==b.size()){
            int x=a[0].compare(b[0]);
            
            return x < 0;
        }
        
        return a.size() > b.size();
    });
    
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}