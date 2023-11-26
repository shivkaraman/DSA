/*
1. You are given a list of words, a list of alphabets(might be repeating) and score of every alphabet 
     from a to z.
2. You have to find the maximum score of any valid set of words formed by using the given 
     alphabets.
3. A word can not be used more than one time.
4. Each alphabet can be used only once. 
5. It is not necessary to use all the given alphabets.

Sample Input
    4
    dog cat dad good
    9
    a b c d d d g o o
    1 0 9 5 0 0 3 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0

Sample Output
    23
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int Score{};
void maxScore(vector<string> words, vector<int> freq, vector<int> scores, int wordNo, int scr){
    if(wordNo == words.size()){
        Score = max(Score, scr);
        return;
    }
    maxScore(words, freq, scores, wordNo + 1, scr); //Not included
    int s{};
    bool yesCall = true; //flag is true if yes call can be made
    for(char &ch : words[wordNo]){ //Check id the current word can be included in the subset
        if(freq[ch - 'a'] == 0){
            yesCall = false;
            break;
        }   
        s += scores[ch - 'a'];
        freq[ch - 'a']--;
    }
    if(yesCall)
        maxScore(words, freq, scores, wordNo + 1, scr + s); //Included
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin >> words[i];
    
    int m;
    cin >> m;
    vector<char> letters(m);
    for(int i = 0; i < m; i++)
        cin >> letters[i];

    vector<int> score(26);
    for(int i = 0; i < 26; i++)
        cin >> score[i];
    
    vector<int> freq(26, 0);
    for(char &ch : letters){
        freq[ch-'a']++;
    }

    maxScore(words, freq, score, 0, 0);
    cout << Score << endl;
}
