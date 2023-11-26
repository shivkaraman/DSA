/*
1. You are given a 10*10 2-D array(board) containing only '+' and '-' characters, which represents a 
    crossword puzzle. 
2. You are also given n number of words which need to be filled into the crossword.
3. Cells containing '-' are to be filled with the given words.

Sample Input
    +-++++++++
    +-++++++++
    +-++++++++
    +-----++++
    +-+++-++++
    +-+++-++++
    +++++-++++
    ++------++
    +++++-++++
    +++++-++++
    4
    LONDON
    DELHI 
    ICELAND 
    ANKARA

Sample Output
    +L++++++++
    +O++++++++
    +N++++++++
    +DELHI++++
    +O+++C++++
    +N+++E++++
    +++++L++++
    ++ANKARA++
    +++++N++++
    +++++D++++
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool canPlacewordHorizontally(vector<vector<char>> board, string word, int sr, int sc){
    /*
    1. No of empty slots = No of letters in word
    2. left and right of word must be +
    3. Word must correctly fit into the empty slot
    */
    if(sc-1 >= 0 && board[sr][sc-1] != '+') //Left side hain and vaha par + nahi pada
        return false;
    if(sc + word.size() < board[0].size() && board[sr][sc+word.size()] != '+') //Right side hain and vaha par + nahi pada
        return false;
    if(sc + word.size() > board[0].size()) //If board size exceeds the no of - spots available
        return false;
    for(int x = 0; x < word.size(); x++){
        if(board[sr][sc+x] == '-' || board[sr][sc+x] == word[x])
            continue;
        else    
            return false;
    }
    return true;
}

bool canPlacewordVertically(vector<vector<char>> board, string word, int sr, int sc){
    /*
    1. No of empty slots = No of letters in word
    2. top  and bottom of word must be +
    3. Word must correctly fit into the empty slot
    */
    if(sr-1 >= 0 && board[sr-1][sc] == '-')
        return false;
    if(sr + word.size() < board.size() && board[sr+word.size()][sc] != '+')
        return false;
    if(sr + word.size() > board.size())
        return false;
    for(int x = 0; x < word.size(); x++){
        if(board[sr+x][sc] == '-' || board[sr+x][sc] == word[x])
            continue;
        else    
            return false;
    }
    return true;
}

vector<bool> placewordHorizontally(vector<vector<char>> &board, string word, int sr, int sc){
    vector<bool> placed(word.size(), false);
    for(int i = 0; i < word.size(); i++){
        if(board[sr][sc+i] == '-'){
            board[sr][sc+i] = word[i];
            placed[i] = true;
        }
    }
    return placed;
}

void unplacewordHorizontally(vector<vector<char>> &board, vector<bool> placed, int sr, int sc){
    for(int i = 0; i <placed.size(); i++){
        if(placed[i])
            board[sr][sc+i] = '-';
    }
}

vector<bool> placewordVertically(vector<vector<char>> &board, string word, int sr, int sc){
    vector<bool> placed(word.size(), false);
    for(int i = 0; i < word.size(); i++){
        if(board[sr+i][sc] == '-'){
            board[sr+i][sc] = word[i];
            placed[i] = true;
        }
    }
    return placed;
}

void unplacewordVertically(vector<vector<char>> &board, vector<bool> placed, int sr, int sc){
     for(int i = 0; i <placed.size(); i++){
        if(placed[i])
            board[sr+i][sc] = '-';
    }
}

void display(vector<vector<char>> board){
    for(vector<char> &vec : board){
        for(char &ch : vec)
            cout << ch << " ";
        cout << endl;
    }
}
//* Level - Words
//* Option- Where to place
void crossWord(vector<vector<char>> board, vector<string> words, int vidx){
    if(vidx == words.size()){
        display(board);
        return;
    }
    string word =  words [vidx];
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if(board[i][j] == '-' || board[i][j] == word[0]){
                if (canPlacewordHorizontally(board, word, i, j)){
                    vector<bool> placed = placewordHorizontally(board, word, i, j);
                    crossWord (board, words, vidx + 1);
                    unplacewordHorizontally(board, placed, i, j);
                }
            }
            if(canPlacewordVertically(board,word, i, j)){
                vector<bool> placed = placewordVertically(board, word, i, j);
                crossWord (board, words, vidx + 1);
                unplacewordVertically(board,placed, i, j);
            }
        }
    }
}

int main(){
    vector<vector<char>> vec(10, vector<char>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            cin >> vec[i][j];
    }
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin >> words[i];
    crossWord(vec, words, 0);
}
