/*
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
30
*/

#include <iostream>
#include <vector>
using namespace std;

// Even this is not a DP problem
int Transaction(vector<int> price){
    int buy = price[0];
    int sell = price[0];
    int profit = 0;
    for(int i = 1; i < price.size(); i++){
        if(price[i] < sell){ //This condition is the first condition and it is a must
            profit += sell-buy;
            sell = buy = price[i];
        }
        else if(price[i] < buy)
            buy = price[i];
        else if(price[i] > sell)
            sell = price[i];
        
    }
    profit += sell-buy;
    return profit;
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

