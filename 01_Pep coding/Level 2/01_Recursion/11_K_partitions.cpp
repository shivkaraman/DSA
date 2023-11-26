/*
1. You are given two integers n and k, where n represents number of elements and k represents 
     number of subsets.
2. You have to partition n elements in k subsets and print all such configurations.

Sample Input
    3
    2

Sample Output
    1. [1, 2] [3] 
    2. [1, 3] [2] 
    3. [1] [2, 3] 
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> kpartition(int n, int k){
    if(n == 0 || k == 0 || k > n){
        vector<string> base;
        return base;
    }
    else if(n == k){
        vector<string> base;
        string s;
        for(int i = 1; i <= k; i++){
            s += '[' + to_string(i) + "] ";
        }
        base.push_back(s);
        return base;
    }
    else if(k == 1){
        vector<string> base;
        string s;
        s += "[1";
        for(int i = 2; i <= n; i++){
            s += ", " + to_string(i);
        }
        s += "] ";
        base.push_back(s);
        return base;
    }
    else if(n == 1){
        vector<string> base;
        base.push_back("[1] ");
        return base;
    }
    vector<string> nm1km1 = kpartition(n-1, k-1);
    vector<string> nm1k = kpartition(n-1, k);
    vector<string> ans;

    for(string &s : nm1km1){
        s += '[' + to_string(n) + "]";
        ans.push_back(s);
    }
    for(string &s : nm1k){
        for(int i = 0; i < s.size(); i++){
            if(s[i+1] == ']'){
                string temp1 = s.substr(0, i+1);
                string temp2 = s.substr(i+1);
                temp1 += ", " + to_string(n) ;
                ans.push_back(temp1+temp2);
            }
        }
    }
    return ans;
}

//* Level -> Number btw 1 and n
//* Option -> 1. To start new subset (increases no of non empty sets)
//*           2. To be a part of an already existing non-empty set(no increase in no of non empty sets)
//* Storage -> 2d Vector of k rows is used to store a subset on each row 
void Kpartition(int i, int n, int k, int NonEmpSet, vector<vector<int>> vec){
    if(i > n){
        static int count = 1;
        if(NonEmpSet == k){
            cout << count << ". ";
            count++;
            for(int x = 0; x < vec.size(); x++){
                cout << "[";
                for(int y = 0; y < vec[x].size(); y++){
                    if(y == vec[x].size()-1)
                        cout << vec[x][y];
                    else 
                        cout << vec[x][y] << ", ";
                }
                cout <<  "] ";
            }
            cout << endl;
        }
        return;
    }
    for(int j = 0; j < vec.size(); j++){
        if(vec[j].size() == 0){ //Start a new subset
            vec[j].push_back(i);
            Kpartition(i+1, n, k, NonEmpSet+1, vec);
            vec[j].pop_back();
            break;
        }
        else{
            vec[j].push_back(i); //Append to an already existing subset
            Kpartition(i+1, n, k, NonEmpSet, vec);
            vec[j].pop_back();
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;

    // int count = 1;
    // vector<string> ans = kpartition(n, k);
    // for(string &s : ans){
    //     cout << count << ". " << s << endl;
    //     count++;
    // }
    vector<vector<int>> vec(k);
    Kpartition(1, n, k, 0, vec);
}