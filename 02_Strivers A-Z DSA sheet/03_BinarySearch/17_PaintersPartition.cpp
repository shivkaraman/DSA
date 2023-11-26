//This has another name Split array largest sum
// https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/
// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

int noOfPainters(vector<int> &boards, int maxT){
    int time = 0, painters = 1;
    for(int i = 0; i < boards.size(); i++){
        if(time + boards[i] <= maxT)
            time += boards[i];
        else{
            time = boards[i];
            painters++;
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        int nop = noOfPainters(boards, mid);

        if(nop > k)
            low = mid+1;
        else {
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}