// https://nados.io/question/number-of-employees-under-every-manager?zen=true
// T(n) = O(n) S(n) = O(n)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<pair<char, int>> solution(vector<pair<char, char>> &vec){
    unordered_map <char, int> mp;
    for(auto &p : vec) mp[p.first] = 0;       //O(n) 

    for(auto &p : vec){                       //O(n)        
        if(p.first == p.second) continue;     //If CEO => Continue  
        if(mp[p.first] == 0) mp[p.second]++;  //IF p.first is an employee -> Increment managers count
        else mp[p.second] += mp[p.first] + 1; //If p.first is a manager   -> Add no of ppl he is managing + himself to his manager
    }    
    vector<pair<char, int>> ans;
    for(auto &p : vec){                         //O(n)
        auto m_to_e = mp.find(p.first); //manager -> No of emp 
        ans.push_back({m_to_e->first, m_to_e->second});
    }
    return ans;
}

void display(vector<pair<char, int>> &ans){
    for(auto &p : ans){
      cout << p.first << " " << p.second << endl;
    }
}
int main(){
    int n;
    cin>>n;

    vector<pair<char, char>> vec(n);
    for(int i = 0; i < n; i++){
        pair<char, char> p;
        cin >> p.first >> p.second;
        vec[i] = p;
    }
    vector<pair<char, int>> ans = solution(vec);
    display(ans);
    return 0;  
}