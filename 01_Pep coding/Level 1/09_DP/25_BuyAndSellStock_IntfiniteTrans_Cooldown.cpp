/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

Sample Input
12 
10 15 17 20 16 18 22 20 22 20 23 25

Sample Output
19
*/
#include <iostream>
#include <vector>
using namespace std;

 /*
 This is very simular to the previous question, but here we introduse a new state called as cooldown, 
 Previously we used to buy a stock on previous sell, but here we buy a stock from previous cooldown
 
 Storage -> Three arrays buy(profit if baught today) , sell(profit if sold today) , cooldown(profit if today was cooldown)
 Meaning -> buy[i] - net profit if share was baught today
            sell[i] - net profit if share was sold today
            cooldown[i] - net profit if today was a cooldown
 traverse & solve ->
           buy[i] :
                 We have two options out of which max is chosen
                   1. Buy a share today on prev sold share ie from cooldown : buy[i] = cooldown[i-1] - todays price
                   2. Hold the share baught earlier : buy[i] = buy[i-1]
           sell[i] :
                 We have two options out of which max is to be chosen
                   1. Sell a share which was baught earlier : sell[i] = todays price - buy[i-1] 
                   2. Do nothing : sell[i] = sell[i-1]
           cool[i] : 
                 We have two options out of which max is to be chosen 
                   1. cool[i] = sell[i-1] coz if today is a cooldown, the share has to be sold yesterday
                   2. Do nothing and carry the prev cooldown as it is cool[i] = cool[i-1]
 */
int transaction(vector<int> arr){
    int buy = -arr[0];
    int sell = 0;
    int cool = 0;

    for(int i = 1; i < arr.size(); i++){
        buy = max(buy, cool - arr[i]);
        cool = max(cool, sell);
        sell = max(sell, buy + arr[i]);
    }
    return sell;
}

int main(){ 
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < arr.size(); i++) {
        cin>> arr[i] ;
    }

    cout << transaction(arr);
    return 0;
}