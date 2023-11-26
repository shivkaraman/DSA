// 1. You are given a number n, representing the number of time-intervals.
// 2. In the next n lines, you are given a pair of space separated numbers.
// 3. The pair of numbers represent the start time and end time of a meeting (first number is start time and second number is end time)
// 4. You are required to merge the meetings and print the merged meetings output in increasing order of start time.
// 6
// 22 28
// 1 8
// 25 27
// 14 19
// 27 30
// 5 12
// 1. Sort 
//      1 8
//      5 12
//      14 19
//      22 28
//      25 27
//      27 30

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    pair<int, int> ti[n];
    for(int i=0; i<n; i++){
        cin>>ti[i].first>>ti[i].second;
    }
    sort(&ti[0], &ti[n-1]+1);
    stack<pair<int, int>> st;

    for(int i=0; i<n; i++){
        int s = ti[i].first;
        int e = ti[i].second;
        if(!st.empty() && st.top().second >= s){
            s = st.top().first;
            if(st.top().second >= e)
                e = st.top().second;
            st.pop();
        }
        st.push({s, e});
    }
    
    stack<pair<int, int>> ans;
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    while(!ans.empty()){
        cout<<ans.top().first<<" "<<ans.top().second<<endl;
        ans.pop();
    }
    return 0;
}