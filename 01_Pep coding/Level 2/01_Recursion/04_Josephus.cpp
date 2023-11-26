/*
1. You are given two numbers N and K.
2. N represents the total number of soldiers standing in a circle having position marked from 0 to N-1.
3. A cruel king wants to execute them but in a different way.
4. He starts executing soldiers from 0th position and proceeds around the circle in clockwise direction.
5. In each step, k-1 soldiers are skipped and the k-th soldier is executed.
6. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed soldiers are removed), until only the last soldier remains, who is given freedom.
7. You have to find the position of that lucky soldier.

Sample Input
    4
    2
Sample Output
    0

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void josephus(vector<bool> &soldiers, int k, int tempK, int idx, int killed){
    if(killed == soldiers.size()-1){
        for(int i = 0; i < soldiers.size(); i++){
            if(soldiers[i]){
                cout << i << endl;
                return;
            }
        }
    }
    if(soldiers[idx] == false) //If already kiled-> Proceed
        josephus(soldiers, k, tempK, (idx+1)%soldiers.size(), killed);
    else if(tempK == 0){ //Kill the soldier as this is Kth soldier
        soldiers[idx] = false;
        josephus(soldiers, k, k-1, (idx+1)%soldiers.size(), killed+1); 
    }
    else //Its not the Kth soldier -> Proceed
        josephus(soldiers, k, tempK-1, (idx+1)%soldiers.size(), killed); 
}


int josephusOptimised(int n, int k){
    if(n == 0)
        return 0;
    int nm1 = josephusOptimised(n-1, k);
    return (nm1+k)%n;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<bool> soldiers(n, true);
    // josephus(soldiers, k, k-1, 0, 0);
    cout << josephusOptimised(n, k) << endl;
}