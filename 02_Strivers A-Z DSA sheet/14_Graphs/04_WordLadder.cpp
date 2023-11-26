// https://www.youtube.com/watch?v=tRPda0rcf8E
// https://leetcode.com/problems/word-ladder/description/

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
    int ladderLength(string startWord, string targetWord, vector<string> &wordList){
        queue<pair<string, int>> q; // <word, moves>
        q.push({startWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
int main(){
    vector<string> vec = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    cout << s.ladderLength("hit", "cog", vec);
    return 0;
}