/*
1. You are given a string which represents digits of a number.
2. You have to create the maximum number by performing at-most k swap operations on its digits.

Sample Input
    1234567
    4
Sample Output
    7654321
*/

#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

//Level - string
//Option - 1. swapping of str[i] with any of str[i+1]-str[n-1] such that str[x] > str[i]
//         2. If there is no str[x] such that str[x] > str[i], then no swap
int mx = INT_MIN;
void largest(string str, int i, int k){
    if(i == str.size() || k < 0){
        return;
    }
    mx = max(mx, stoi(str));
    bool swapped = false;
    for(int idx = i+1; idx < str.size(); idx++){
        if(str[idx] > str[i]){
            swapped = true;
            swap(str[i], str[idx]);
            largest(str, i+1, k-1);
            swap(str[i], str[idx]);
        }
    }
    if(!swapped)
        largest(str, i+1, k);
}
 
int main(){
    string str;
    cin >> str;

    int k;
    cin >> k;

    largest(str, 0, k);
    cout << mx << endl;
    return 0;
}