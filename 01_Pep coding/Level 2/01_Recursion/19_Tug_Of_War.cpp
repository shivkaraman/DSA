/*
1. You are given an array of n integers.
2. You have to divide these n integers into 2 subsets such that the difference of sum of two subsets 
     is as minimum as possible.
3. If n is even, both set will contain exactly n/2 elements. If n is odd, one set will contain (n-1)/2 and 
    other set will contain (n+1)/2 elements.
3. If it is not possible to divide, then print "-1".

Sample Input
    6
    1 2 3 4 5 6
Sample Output
    [1, 3, 6] [2, 4, 5]
*/

#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

string answer(vector<int> left, vector<int> right){
    string str = "[";
    for(int i = 0; i < left.size(); i++){
        if(i == left.size()-1)
            str += to_string(left[i]);
        else
            str += to_string(left[i]) + ", ";
    }
    str += "] [";
    for(int i = 0; i < right.size(); i++){
        if(i == right.size()-1)
            str += to_string(right[i]);
        else
            str += to_string(right[i]) + ", ";
    }
    str+= "]";
    return str;
}

//* Level - element ie vec[i]
//* Option - Can go to left or right subset if size permits
string ans;
void tugOfWar(vector<int> vec, int i, vector<int> left, vector<int> right, int sumOfLeft, int sumOfRight){
    if(i == vec.size()){
        if(left.size() == right.size() || abs(int(left.size()-right.size())) == 1){
            static int mn = INT_MAX;
            int diff = abs(sumOfLeft - sumOfRight);
            if(diff < mn){
                mn = diff;
                ans = answer(left, right);
            }
        }
        return;
    }
    if(left.size() < (vec.size()+1) / 2){
        left.push_back(vec[i]);
        tugOfWar(vec, i+1, left, right, sumOfLeft + vec[i], sumOfRight);
        left.pop_back();
    }

    if(right.size() < (vec.size()+1) / 2){
        right.push_back(vec[i]);
        tugOfWar(vec, i+1, left, right, sumOfLeft, sumOfRight + vec[i]);
        right.pop_back();
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> vec;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    vector<int> left, right;
    tugOfWar(vec, 0, left, right, 0, 0);

    if(ans.size() == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}