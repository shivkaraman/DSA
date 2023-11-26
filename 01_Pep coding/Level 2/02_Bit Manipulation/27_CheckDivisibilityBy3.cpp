/*
1. You are given a binary string which represents a number.
2. You have to check whether this number is divisible by 3 or not.
3. Print 'true' if it is divisible by 3, otherwise print 'false'.

Sample Input
    10010101010001
Sample Output
    false
*/


#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;

    //Watch Video
    int odd = 0 ;
    int even = 0 ;
    for ( int i = 0 ; i < str.size() ; i ++ ){
        int bit = str[i] - '0';
        if ( i % 2 == 0 ) 
            even += bit;
        else 
            odd += bit;
    }
    int delta = even - odd ;
    if (delta % 11 == 0)
        cout << "true" << endl;
    else 
        cout << "false" << endl;
    return 0;
}