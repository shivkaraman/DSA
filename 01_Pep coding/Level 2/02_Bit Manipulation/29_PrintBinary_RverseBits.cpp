/*
1. You are given a number.
2. You have to print its binary representation.
3. You also have to reverse the bits of n and print the number obtained after reversing the bits.

Sample Input
    11
Sample Output
    1011
    13
*/


#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool flag = false;
    int rev = 0, revBitCnt = 0;
    for(int i = 31 ; i >= 0 ; i--){
        int mask = ( 1 << i );
        if(flag){
            if((mask & n) != 0){
                cout << 1;
                rev |= (1 << revBitCnt);
            }
            else
                cout << 0; 
            revBitCnt++;
        }
        else{
            if((mask & n) != 0){
                flag = true;
                cout << 1;
                rev |= (1 << revBitCnt);
                revBitCnt++;
            }
        }
    }
    cout << endl << rev << endl;
    return 0;
}