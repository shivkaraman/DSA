
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool canPlacewordHorizontally(vector<vector<char>> arr, string word, int sr, int sc){
    if(sc-1 >= 0 && arr[sr][sc-1] != '+')
        return false;
    if(sc + word.size() < arr[0].size() && arr[sr][sc+word.size()] != '+')
        return false;
    if(sc + word.size() > arr[0].size())
        return false;
    for(int x = 0; x < word.size(); x++){
        if(arr[sr][sc+x] == '-' || arr[sr][sc+x] == word[x])
            continue;
        else    
            return false;
    }
    return true;
}

bool canPlacewordVertically(vector<vector<char>> arr, string word, int sr, int sc){
    if(sr-1 >= 0 && arr[sr-1][sc] == '-')
        return false;
    if(sr + word.size() < arr.size() && arr[sr+word.size()][sc] != '+')
        return false;
    if(sr + word.size() > arr.size())
        return false;
    for(int x = 0; x < word.size(); x++){
        if(arr[sr+x][sc] == '-' || arr[sr+x][sc] == word[x])
            continue;
        else    
            return false;
    }
    return true;
}

vector<bool> placewordHorizontally(vector<vector<char>> &arr, string word, int sr, int sc){
    vector<bool> placed(word.size(), false);
    for(int i = 0; i < word.size(); i++){
        if(arr[sr][sc+i] == '-'){
            arr[sr][sc+i] = word[i];
            placed[i] = true;
        }
    }
    return placed;
}

void unplacewordHorizontally(vector<vector<char>> &arr, vector<bool> placed, int sr, int sc){
    for(int i = 0; i <placed.size(); i++){
        if(placed[i])
            arr[sr][sc+i] = '-';
    }
}

vector<bool> placewordVertically(vector<vector<char>> &arr, string word, int sr, int sc){
    vector<bool> placed(word.size(), false);
    for(int i = 0; i < word.size(); i++){
        if(arr[sr+i][sc] == '-'){
            arr[sr+i][sc] = word[i];
            placed[i] = true;
        }
    }
    return placed;
}

void unplacewordVertically(vector<vector<char>> &arr, vector<bool> placed, int sr, int sc){
     for(int i = 0; i <placed.size(); i++){
        if(placed[i])
            arr[sr+i][sc] = '-';
    }
}

void display(vector<vector<char>> arr){
    for(vector<char> &vec : arr){
        for(char &ch : vec)
            cout << ch << " ";
        cout << endl;
    }
}

void crossWord(vector<vector<char>> arr, vector<string> words, int vidx){
    if(vidx == words.size()){
        display(arr);
        return;
    }
    string word =  words [vidx];
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            if(arr[i][j] == '-' || arr[i][j] == word[0]){
                if (canPlacewordHorizontally(arr, word, i, j)){
                    vector<bool> placed = placewordHorizontally(arr, word, i, j);
                    crossWord (arr, words, vidx + 1);
                    unplacewordHorizontally(arr, placed, i, j);
                }
            }
            if(canPlacewordVertically(arr,word, i, j)){
                vector<bool> placed = placewordVertically(arr, word, i, j);
                crossWord (arr, words, vidx + 1);
                unplacewordVertically(arr,placed, i, j);
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
