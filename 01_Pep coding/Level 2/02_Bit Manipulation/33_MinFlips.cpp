/*
You are given 3 positive numbers a, b and c. You have to return the minimum number of flips required in some bits of a and b to make ( a OR b == c ) (bitwise OR operation).
The flip operation consists of changing any single bit 1 to 0 or changing the bit 0 to 1 in their binary representation.

Sample Input
    2
    6
    5
Sample Output
    3

Solution 
1. We check a b and c bit by bit
    first we create mask of a b and c -> bit 0 of a b c
    if  (amask|bmask)^cmask = 0  ---> No change coz bits are already same
        (amask|bmask)^cmask = 1  ---> Change required
2. We need to figure out if change required is in a or b or both
        if c = 1  => a|b = 0
                    This is possible only when a=b=0 
                    => changing a=1 OR b=1 does the job
            => Increase count by 1
        if c = 0 => a|b = 1
                    This is possible when 
                        1. a=0/1 b=1/0 
                            we need toc change one of them to 0(which is currently 1)
                            => Icnrease count by 1
                        2. a=b=1
                            we need to change both a and b to 0
                            => Increase count by 2
*/

#include <iostream>
using namespace std;

void solution(int a, int b, int c){
    int count = 0;
    while(a | b | c){
        int amask = (a & 1);
        int bmask = (b & 1);
        int cmask = (c & 1);
        if( ((amask | bmask) ^ cmask) != 0){ //Change required
                if((cmask & 1) == 1){       //Implies a|b=0 => a=b=0  => a=1 or b=1 makes a|b=1
                    count++;
                }
                else{                        //Implies a|b=1 => a=0/1, b=1/0 OR a=b=1
                    if((amask & bmask) == 0) // a=0/1, b=0/1
                        count++; 
                    else                     //  a=b=1
                        count += 2;
                }
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    cout << count << endl;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    solution(a, b, c);
    return 0;
}