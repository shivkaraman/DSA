// https://www.youtube.com/watch?v=ceRJzjBrhPU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=14
// A subarray is equivalent if,
//    count of unique integers in the subarray = count of unique integers in the given array.
//This questions looks same as prev question with k=no of unique elements -> Yes it is but we can solve with a better approach => WATCH VIDEO

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> &arr, int k) {
    unordered_map<int, int> mp;
    int unique = 0, i = 0, j = 0;
    int ans = 0;
    while(true){
        bool flag1 = 0, flag2 = 0;
        //Acquire till unique < k
        while(i < arr.size() && unique < k){
            flag1 = true;
            int val = arr[i];
            if(mp.find(val) == mp.end()) unique++;
            mp[val]++;
            i++;
        }
        while(j < i && unique == k){
            flag2 = true;
            //Collect answer
            ans += arr.size() - (i-1);

            //Release till unique = k
            int val = arr[j++];
            if(mp[val] == 1){
                unique--;
                mp.erase(val);
                break;
            }
            else mp[val]--;
        }
        if(!flag1 && !flag2) break;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    unordered_set<int> set;
    for (int i = 0 ; i  < n; i++) {
        cin >> arr[i];
        set.insert(arr[i]);
    }
    cout << solution(arr, set.size());
}
