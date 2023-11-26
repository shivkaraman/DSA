// Infinite transaction with transaction fee

/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are give a number fee, representing the transaction fee for every transaction.
4. You are required to print the maximum profit you can make if you are allowed infinite transactions, but has to pay "fee" for every closed transaction.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

Sample Input
12 
10 15 17 20 16 18 22 20 22 20 23 25 3

Sample Output
13
*/
#include <iostream>
#include <vector>

using namespace std;
/*
Storage -> We require two arrays buy(profit if baught today) & sell(profit if sold today)
Meaning -> buy[i] - net profit if share was baught today
           sell[i] - net profit if share was sold today
traverse & solve ->
          buy[i] :
                We have two options out of which max is chosen
                  1. Buy a share today on prev sold share : buy[i] = sell[i-1] - todays price
                  2. Hold the share baught earlier : buy[i] = buy[i-1]
          sell[i] :
                We have two options out of which max is to be chosen
                  1. Sell a share which was baught earlier : sell[i] = todays price - buy[i-1] - fee
                  2. Do nothing : sell[i] = sell[i-1]
*/
int transactions(vector<int> arr,int fee){
    int n = arr.size();
    int buy = -arr[0];
    int sell = 0;

    for(int i = 1; i < n; i++){
        int buyToday = sell - arr[i];
        int sellToday = buy + arr[i] - fee;

        buy = max(buy, buyToday);
        sell = max(sell, sellToday);
    }
    return max(buy, sell);
}

int main() {
    int n;
    cin>> n; 
    vector<int> arr(n,0);
    for (int i = 0; i < arr.size(); i++) {
        cin>> arr[i];
    }
    int fee;
    cin>> fee;

    cout << transactions(arr,fee);
    return 0;
}