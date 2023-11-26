#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> arr) {
    //map <sum, freq>
    unordered_map<int, int> mp;
    int cumSum = 0, count = 0;
    for(int i = 0;i < arr.size(); i++){
        cumSum += arr[i];
        auto it = mp.find(cumSum);
        if(it != mp.end()){
            count += mp[cumSum];
            mp[cumSum]++;
        }
        else mp[cumSum] = 1;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    };

    cout << solution(arr);
    return 0;
}