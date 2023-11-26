#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
In permutation-1 we used pure permutation
    level-item
    Option - in which box to place
In this problem, we are using combination and then arranging them to get permutation
ie nPr = nCr x r!
    level-box
    option - Item ayega/nahi-ayega (AS IN COMBINATION)
             Agar ayega to konsa item ayega(GENERATING PERMUTATION FROM COMBINATION)

*/
void permutation(string str, int boxNo, int totBox, int selItems, vector<int> usedItems){
    if(boxNo == totBox+1){
        if(selItems == usedItems.size())
            cout << str << endl;
        return;
    }
    //Konsa item dalna he
    for(int item = 0; item < usedItems.size(); item++){
        if(usedItems[item] == false){
            usedItems[item] = true;
            permutation(str + to_string(item+1), boxNo+1, totBox, selItems+1, usedItems);
            usedItems[item] = false;
        }
    }
    //Item nahi dalna
    permutation(str + "0", boxNo+1, totBox, selItems, usedItems);
}

int main(){
    int n, k;
    cin >> n >> k;

    string str;
    vector<int> usedItems(k, 0);
    permutation(str, 1, n, 0, usedItems);
}