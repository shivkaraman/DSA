/*
1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).
2. You are required to place the items in those boxes and print all such configurations possible.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Level - item
//options - box
void permutations(vector<int> boxes, int item, int totalItem){
    if(totalItem > boxes.size()){
        return;
    }
    if(item == totalItem+1){
        for_each(boxes.begin(), boxes.end(), [](int x){cout << x;});
        cout << endl;
        return;
    }
    for(int box = 0; box < boxes.size(); box++){
        if(boxes[box] == 0){
            boxes[box] = item;
            permutations(boxes, item+1, totalItem);
            boxes[box] = 0;
        }
    }
}
int main(){
    int n, k; 
    cin >> n >> k;

    vector<int> vec(n, 0);
    permutations(vec, 1, k);
}