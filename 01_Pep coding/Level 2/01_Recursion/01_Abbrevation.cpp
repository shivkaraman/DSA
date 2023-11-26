/*
1. You are given a word.
2. You have to generate all abbrevations of that word.

Example
    Sample Input
        pep
    Sample Output
        pep
        pe1
        p1p
        p2
        1ep
        1e1
        2p
        3
LOGIC
    000 -> pep
    001 -> pe1
    010 -> p1p
    011 -> p2
    100 -> 1ep
    101 -> 1e1
    110 -> 2p
    111 -> 3
*/

#include<iostream>
using namespace std;
 
void solution(string str, string asf,int count, int pos){
    if(pos == str.size()){
        if(asf.size() < str.size() && count)
            cout << asf + to_string(count) << endl;
        else
            cout << asf << endl;
        return;
    }
    //Option 1 -> Ayega -> append count to string and set count to 0
    if(count > 0) //Settling prev unincluded chars
        solution(str, asf + to_string(count) + str[pos], 0 , pos + 1);
    else
        solution(str, asf + str[pos], count , pos + 1);
    //Option 2 -> Nahi ayega -> increase count
    solution(str, asf, count + 1 , pos + 1);
} 
int main() {
    string str;
    cin >> str;
    solution(str,"",0,0);
    return 0;
}