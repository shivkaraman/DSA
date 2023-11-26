/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed two transactions.

Sample Input
9 
11 6 7 19 4 1 6 18 4

Sample Output
30
*/

#include <iostream>
#include <vector>
using namespace std;

/*
This is a variation of 1 Transaction allowed 
1st iteration is the same ie Aaj sell karna fixed hain, to hum past me jate the aur least buying price pr buy karte the
2nd iteration is slightly different, we iterate in reverse derection and we do the following 
    Aaj buy karna fix he aur hum ab future me jayenge aur maximum price pe sell karenge

Initially, this was my approach. BUT THIS DOESNOT WORK
    int lsf = INT_MAX;  //Least so far
    int op1 = 0, op2=0; //Overall max profit
    int pist = 0;       //Profit if sold today
    for(int i = 0; i < price.size(); i++){
        if(price[i] < lsf)
            lsf = price[i];

        pist = price[i] - lsf;
        if(pist >= op1){
            op2 = op1;
            op1 = pist;
        }
    }
For example : 5 0 3 1 4
        5
         \           4
          \     3   /
           \   / \ /
            \ /   1
             0
    From 0, lsf = 0
    When we reach 3, pist=3 and op1 will become 3
    But after that, lsf is not updated and when we reach 4, pist=4 and op1=4 and op2=3 WHICH IS NOT POSSIBLE BECAUSE FOR BOTH THE 
    SELLING 0 IS THE BUYING DAY. 
    This approach is not taking care about buying day must come after selling day

The following approach works because it is taking care of buying and selling days
How is it taking care?
Say at index i, the first iterations indicates IS DIN SE PEHLE BUY OR SELL KHATAM HOJAYE TO MAX PROFIT KITNE BANENGE
                the second iteration indicates IS DIN KE BAAD  BUY OR SELL KHATAM HOJAYE TO MAX PROFIT KITNE BANENGE
So the second buy is happening only after selling the first stock
                
*/
int Transaction(vector<int> arr){
    int lsf = arr[0];              //Least so far
    int mpist = 0;                 // Max profit if sold today
    vector<int> dp(arr.size(), 0); //Max profit in sold until today
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < lsf)
        lsf = arr[i];
        mpist = arr[i] - lsf;
        dp[i] = max(dp[i-1], mpist);
    }

    int msf = arr[arr.size()-1];    //Max so far
    int mpibt = 0;                  //Max profit if baught today
    vector<int> dp2(arr.size(), 0); //Max profit in baught until today
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i] > msf)
        msf = arr[i];
        mpibt = msf - arr[i];
        dp2[i] = max(dp2[i+1], mpibt); 
    }

    int mp = 0; //Max prfit
    for(int i = 0; i < dp.size(); i++){
        if(dp[i] + dp2[i] > mp)
        mp = dp[i] + dp2[i];
    }
    return mp;
}

int  main() {
    int n;
    cin>>n;
    vector<int>arr(n, 0);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    cout << Transaction(arr);
    return 0;  
}

