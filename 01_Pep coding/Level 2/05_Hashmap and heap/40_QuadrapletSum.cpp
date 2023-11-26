/*\
1. You are given four arrays(A1,A2,A3,A4) of integers and an integet target. All arrays are of same length(N).
2. You have to find the count of all unique quadruplets(a,b,c,d) such that - 
   A1[a] + A2[b] + A3[c] + A4[d] = target.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void input(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
}

int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D, int target){
    // map <sum, freq>
    unordered_map<int, int> mp;
    int count = 0;
    for(int a : A){
        for(int b : B) mp[a+b]++;
    }

    for(int c : C){
        for(int d : D){
            count += mp[target - (c+d)];
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr1(n, 0);
    vector<int> arr2(n, 0);
    vector<int> arr3(n, 0);
    vector<int> arr4(n, 0);

    input(arr1);
    input(arr2);
    input(arr3);
    input(arr4);

    int target;
    cin >> target;
    cout << fourSumCount(arr1, arr2, arr3, arr4, target);
    return 0;
}