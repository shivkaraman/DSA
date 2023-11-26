
#include<iostream>
#include<vector>
using namespace std;

/*
In combination
    level - box
    option - to place item or not
In combinations-2, we are using permutation to generate combination
ie nCr = nPr x 1/r!
    level-items
    option-in which box to place item (like permutation)
           But here we can place current item only in boxes next to box in which prev
           item was placed(which prevents permutation among same boxes)
           WATCH VIDEO
*/

void combinations(vector<bool> boxes, int currItem, int ritems, int prevBox){
    if(currItem > ritems){
        for(bool i : boxes){
            if(i)
                cout << "i";
            else
                cout << "-";
        }
        cout << endl;
        return;
    }
    for(int box = prevBox+1; box < boxes.size(); box++){
        if(boxes[box] == false){
            boxes[box] = true;
            combinations(boxes, currItem+1, ritems, box);
            boxes[box] = false;
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;

    vector<bool>boxes(n, false);
    combinations(boxes, 1, k, -1);
}