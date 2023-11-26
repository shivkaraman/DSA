
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pist = 0, minPrice = INT_MAX;
        int maxProfit = 0;
        for(int price: prices){
            minPrice = min(minPrice, price);
            pist = price - minPrice;
            maxProfit = max(maxProfit, pist);
        }
        return maxProfit;
    }
};

int main(){
    
    return 0;
}