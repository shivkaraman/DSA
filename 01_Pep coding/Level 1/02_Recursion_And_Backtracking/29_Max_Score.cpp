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
    //Word not included
    maxScore(words, freq, scores, wordNo + 1, scr);
    //Word included
    int s{};
    bool yesCall = true;
    for(char &ch : words[wordNo]){
        if(freq[ch - 'a'] == 0){
            yesCall = false;
            break;
        }   
        s += scores[ch - 'a'];
        freq[ch - 'a']--;
    }
    if(yesCall)
        maxScore(words, freq, scores, wordNo + 1, scr + s);
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
