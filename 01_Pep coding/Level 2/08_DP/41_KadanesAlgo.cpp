//Maximuum sum subarray


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int kadanes(vector<int> &arr){
    int currSum = arr[0];
    int mxSum = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(currSum >= 0)
            currSum += arr[i];
        else    
            currSum = arr[i];
        mxSum = max(mxSum, currSum);
    }
    return mxSum;   
}

int main(){
    vector<int> arr = {-1, -2};
    cout << kadanes(arr);
    return 0;
}