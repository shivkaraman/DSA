/*
1. You are give a number of boxes (nboxes) and number of identical items (ritems).
2. You are required to place the items in those boxes and print all such configurations possible.
*/

#include<iostream>
#include<string>
using namespace std;

/*
In permutation 
    level - Number(item)
    option - which box to place
In combination
    level - box
    option - to place item or not
*/
void combinations(string str, int i, int n, int k){
    if(i == n){
        if(k == 0)
            cout << str << endl;
        return;
    }
    combinations(str + "i", i+1, n, k-1);
    combinations(str + "-", i+1, n, k);
}
int main(){
    int n, k;
    cin >> n >> k;

    combinations("", 0,n, k);
}