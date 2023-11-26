/*
1. You are given an array of n distinct integers.
2. You have to divide these n integers into k non-empty subsets such that sum of integers of every 
     subset is same.
3. If it is not possible to divide, then print "-1".

Sample Input
    6 
    1 2 3 4 5 6 
    3
Sample Output
    [1, 6] [2, 5] [3, 4] 
*/

#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>> sets){
    for(int x = 0; x < sets.size();x++){
        cout << "[";
        for(int y = 0; y < sets[x].size(); y++){
            if(y == sets[x].size()-1)
                cout << sets[x][y];
            else    
                 cout << sets[x][y] << ", ";
        }
        cout << "] ";
    }
    cout << endl;
}

void kSubsetEqual(int i, int k, int nonEmpty, vector<int>vec, vector<vector<int>> sets){
    if(i == vec.size()){
        if(nonEmpty == sets.size()){
            int sum, flag = 1;
            for(int x = 0; x < sets.size();x++){
                int tsum{};
                for(int y = 0; y < sets[x].size(); y++){
                  tsum+=sets[x][y];
                }
                if(x == 0)  
                    sum = tsum;
                else if(tsum != sum){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                display(sets);
        }
        return;
    }
    for(int j = 0; j < sets.size();j++){
        if(sets[j].size() == 0){
            sets[j].push_back(vec[i]);
            kSubsetEqual(i+1, k, nonEmpty+1, vec, sets);
            sets[j].erase(sets[j].begin() + sets[j].size()-1);
            break;
        }
        else{
            sets[j].push_back(vec[i]);
            kSubsetEqual(i+1, k, nonEmpty, vec, sets);
            sets[j].erase(sets[j].begin() + sets[j].size()-1);
        }
    }
}

int main(){
    int n;
    cin >> n;
   
    vector<int> vec(n);
    for(int i = 0;i < n; i++)
        cin >> vec[i];
   
    int k;
    cin >> k;
    vector<vector<int>> sets(k);
    kSubsetEqual(0, k, 0, vec, sets);
}