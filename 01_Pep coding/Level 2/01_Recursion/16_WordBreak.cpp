/*
1. You are given n space separated strings, which represents a dictionary of words.
2. You are given another string which represents a sentence.
3. You have to print all possible sentences from the string, such that words of the sentence are 
   present in dictionary.

Sample Input
    11
    i like pep coding pepper eating mango man go in pepcoding
    ilikepeppereatingmangoinpepcoding

Sample Output
    i like pepper eating man go in pep coding 
    i like pepper eating man go in pepcoding 
    i like pepper eating mango in pep coding 
    i like pepper eating mango in pepcoding 
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//Level - String
//Option - find a word that is part of given library of words and append it to ans
void wordBreak(vector<string> vec, string que, string asf, int i){
    if(i == que.size()){
        cout << asf << endl;
        return;
    }
    for(int j = i, count = 1; j < que.size(); j++, count++){
        string temp = que.substr(i, count);
        auto it = find(vec.begin(), vec.end(), temp);
        if(it != vec.end())
            wordBreak(vec, que, asf + temp + " ", i+temp.size());
    }
}

int main(){
    int n;
    cin >> n;

    vector<string> vec(n);
    for(int i = 0; i < n; i++){
       cin >> vec[i];
    }
    
    string str;
    cin >> str;

    wordBreak(vec, str, "", 0);
}