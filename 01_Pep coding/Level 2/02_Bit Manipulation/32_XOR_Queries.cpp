/*
You are given an array of integers. You are also given a two dimensionsal array queries where queries[i] = [lefti, righti].

For each ith query you have to compute the XOR of elements all the elements from index lefti to righti 
(that is, arr[lefti] XOR arr[lefti + 1] XOR arr[lefti + 2]... XOR arr[righti] )

Sample Input
    4
    1 3 4 8
    4
    0 1
    1 2
    0 3
    3 3
Sample Output
    2 7 14 8

We use the property a^a = 0 in this question
1. Create an array and store XOR of all elements from 0 to i 
    elements ->      a     b       c         d           e
    XORtilli ->  0   0^a   0^a^b   0^a^b^c   0^a^b^c^d   0^a^b^c^d^e
2. For a query (li, ri)
    xorQuery = XORtilli[ri+1] ^ XORtilli[li] 

    eg: for Query (c , e)
        xorQuery = XORtilli[e] ^ XORtilli[b] 
                 = 0^a^b^c^d^e ^ 0^a^b
                 = c^d^e
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void xorQueries(vector<int> arr, vector<pair<int, int>> queries){
    vector<int> XORtilli(arr.size()+1);
    int XOR = 0;
    XORtilli[0] = 0;
    for(int i = 1; i <= arr.size(); i++){
        XOR ^= arr[i-1];
        XORtilli[i] = XOR;
    }
    //Printing XOR Queries
    for(pair<int, int> &p : queries){
        int lefti = p.first;
        int righti = p.second;
        int XORQ = (XORtilli[righti+1] ^ XORtilli[lefti]);
        cout << XORQ << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    vector<pair<int, int>> queries(k);
    for(int i = 0; i < k; i++)
        cin >> queries[i].first >> queries[i].second;

    xorQueries(arr, queries);
    return 0;
}