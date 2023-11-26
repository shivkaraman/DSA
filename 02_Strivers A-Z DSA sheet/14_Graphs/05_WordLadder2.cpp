// https://www.youtube.com/watch?v=DREutrv2XD0
// https://leetcode.com/problems/word-ladder-ii/

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

class Solution{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList){
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<vector<string>> q; //queue<path>
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty()){
            vector<string> pathTillNow = q.front();
            q.pop();

            if (pathTillNow.size() > level){ //Removing all the visited words from wordSet
                level++;
                for (auto it : usedOnLevel){
                    wordSet.erase(it);
                }
            }

            string word = pathTillNow.back();

            if (word == endWord){
                if (ans.size() == 0)
                    ans.push_back(pathTillNow);
                else if (ans[0].size() == pathTillNow.size())
                    ans.push_back(pathTillNow);
            }
            for (int i = 0; i < word.size(); i++){   
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if (wordSet.count(word) > 0){ 
                        pathTillNow.push_back(word);
                        q.push(pathTillNow); //VVIP -> Here we donot erase the pushed word from wordSet immedietly. We delete the word in the next step (first step after popping from queue). This is because this same word can be used for some other path as well
                        usedOnLevel.push_back(word);
                        pathTillNow.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

bool comp(vector<string> a, vector<string> b){
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}


int main(){
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
    
    if (ans.size() == 0)
        cout << -1 << endl;
    else{
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}