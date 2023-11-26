// https://www.geeksforgeeks.org/job-sequencing-problem/

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

bool compare(const vector<int> &v1, const vector<int> &v2){
    return v1[2] > v2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs){
    sort(jobs.begin(), jobs.end(), compare); //Sortin in decreasing order based on profit

    int maxT = 0;
    for(int i = 0; i < jobs.size(); i++){
        maxT = max(maxT, jobs[i][1]);
    }

    int count = 0, sum = 0;
    vector<int> dp(maxT+1, 0);
    for(int i = 0; i < jobs.size(); i++){
        int t = jobs[i][1];
        int p = jobs[i][2];
    
        for(int idx = t; idx >= 1; idx--){
            if(dp[idx] < p){
                dp[idx] = p;
                sum += p;
                count++;
                break;
            }
        }
    }
    return {count, sum};
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> jobs;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        jobs.push_back({x,y,z});
    }
    jobScheduling(jobs);
    return 0;
}