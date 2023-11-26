/*
1. You are given N number of words.
2. You are given M puzzles in the form of M strings.
3. For a given puzzle, a word is valid if both the following conditions are confirmed - 
    Condition 1 -> Word contains the first letter of puzzle.
    Condition 2 -> For each letter in word, that letter should be present in puzzle.
4. You have to print the number of valid words corresponding to a puzzle.

Sample Input
    7
    aaaa asas able ability actt actor access 
    6
    aboveyz abrodyz abslute absoryz actresz gaswxyz

Sample Output
    aboveyz -> 1
    abrodyz -> 1
    abslute -> 3
    absoryz -> 2
    actresz -> 4
    gaswxyz -> 0
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles, vector<int> wordMap, vector<int> puzzleMap){
    vector<int> ans(puzzles.size());
    for(int i = 0; i < puzzles.size(); i++){
        for(int j = 0; j < words.size(); j++){
            bool firstLetter = (((1 << words[j][0]-'a') & (1 << puzzles[i][0]-'a')) != 0);
            bool allLetters = ((puzzleMap[i] & wordMap[j]) == wordMap[j]);
            if(firstLetter && allLetters){
                ans[i] = j+1;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    vector<int> wordMap(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> words[i];
        for(char ch : words[i]){
            wordMap[i] = wordMap[i] | (1 << (ch-'a'));
        }
    }

    int m;
    cin >> m;
    vector<string> puzzles(m);
    vector<int> puzzleMap(m, 0);
    for(int i = 0; i < m; ++i){
        cin >> puzzles[i];
        for(char ch : puzzles[i]){
            puzzleMap[i] = puzzleMap[i] | (1 << (ch-'a'));
        }
    }

    vector<int> ans = findNumOfValidWords(words, puzzles, wordMap, puzzleMap);
    for (int i = 0; i < m; ++i)
        cout << puzzles[i] << " -> " << ans[i] << "\n";
    return 0;
} 