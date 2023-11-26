/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed a single transaction.

Sample Input
9
11
6
7
19
4
1
6
18
4

Sample Output
17
*/

#include <iostream>
#include <vector>
using namespace std;

/*
In this question, the approach is that we are fixing that we will sell the stock today
If we are selling the stock today, the profit is maximised if se had baught the stock when it was minimum price until today.
So we find the min price until today ie lsf
*/
void Transaction(vector<int> price){
    int lsf = INT_MAX; //Least so far
    int op = 0;        //Overall max profit
    int pist = 0;      //profit of sold today
    for(int i = 0; i < price.size(); i++){
        if(price[i] < lsf)
            lsf = price[i];

        pist = price[i] - lsf;
        if(pist > op)
            op = pist;
    }
    cout << op;
}

int  main() {
    int n;
    cin>>n;
    vector<int>arr(n, 0);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    Transaction(arr);
    return 0;  
}

