/*
1. You are given an array of numbers.
2. All numbers occur twice in the array except one.
3. You have to find that number by traversing only once in the array and without using any extra 
     space.     

Sample Input
    5
    23 27 23 17 17
Sample Output
    27
*/

#include<bits/stdc++.h>
using namespace std;
/*
xor operator -> b ^ 1 = b'
                b ^ 0 = b
Property of xor
1. associative
2. commutative

We use the above things to solve this problem 
WKT  number ^ number = 0
     number ^ 0 = number
so in this problem if we iterate over the array elements and xor them, we get the ans
23 27 23 17 17 27 8

23^27^23^8^17^17^27 = 23^23 ^ 27^27 ^ 17^17 ^ 8
                    = 0^0^0^8
                    = 8
*/
int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int unique = 0;
    for(int i = 0; i < n; i++)
        unique ^= arr[i];
    
    cout << unique << endl;
}