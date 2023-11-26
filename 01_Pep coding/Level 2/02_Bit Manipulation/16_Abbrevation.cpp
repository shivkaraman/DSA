/*
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
*/

#include<bits/stdc++.h>
using namespace std;
/*
000 -> pep
001 -> pe1
010 -> p1p
011 -> p2
100 -> 1ep
101 -> 1e1
110 -> 2p
111 -> 3
*/
void solve(string str){
    for(int i = 0; i < (1 << str.size())/*2^str.size()*/; i++){
        int count = 0;
        for(int j = 0; j < str.size(); j++){
            int mask = (1 << (str.size()-1-j));
            if((mask & i) == 0){
                if(count != 0){
                    cout << count << str[j];
                    count = 0;
                }
                else
                    cout << str[j];
            }
            else
                count++;
        }
        if(count)
            cout << count << endl;
        else
            cout << endl;
    }
}

int main(){
    string str;
    cin>>str;
    
    solve(str);
}