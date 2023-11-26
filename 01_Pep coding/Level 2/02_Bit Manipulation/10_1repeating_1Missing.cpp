/*
1. You are given an array of length n containing numbers from 1 to n.
2. One number is present twice in array and one is missing.
3. You have to find these two numbers.

Sample Input
    7 
    1  3  4  5  1  6  2
Sample Output
    Missing Number -> 7
    Repeating Number -> 1
*/

#include<bits/stdc++.h>
using namespace std;
/*
1. mXORr all the input array elements
2. mXORr 1-n
    1 1 2 3 4 5 6 
      1 2 3 4 5 6 7
    = 1^7
3. This gives mXORr of missing element and repeating element
4. Find the two numbers from obtained result using RSB mask
*/
void solution(vector<int> &v1){
    int mXORr = 0;//missing XOR repeating
    for(int i = 0; i < v1.size(); i++){
        mXORr ^= v1[i];
    }
    for(int i = 1; i <= v1.size(); i++){
        mXORr ^= i;
    }
    int rsbm = mXORr & -mXORr;
    int n1{}, n2{};
    for(int i = 0; i < v1.size(); i++){
        if((v1[i] & rsbm) == 0)
            n1 ^= v1[i];
        else
            n2 ^= v1[i];
    }
    for(int i = 1; i <= v1.size(); i++){
        if((i & rsbm) == 0)
            n1 ^= i;
        else
            n2 ^= i;
    }

    for(int i = 0; i < v1.size(); i++){
        if(v1[i] == n1){
            cout << "Missing Number -> " << n2 << endl << "Repeating Number -> " << n1;
            break;
        }
        else if(v1[i] == n2){
            cout << "Missing Number -> " << n1 << endl << "Repeating Number -> " << n2;
            break;
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> v1(n);
    for(int i=0;i<n;++i) 
        cin>>v1[i];

    solution(v1);
    return 0;
}      