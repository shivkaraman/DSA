//Max no o consecutive ones if you are allowed to flip atmmost one 0
// https://nados.io/question/maximum-consecutive-ones-1?zen=true

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> &arr, int k) {
    int ans = 0, i = 0, j = -1;
    bool flip = false;
    while(true){
        bool flag1 = 0, flag2 = 0;
        //Acquire till you find a second zero
        while(i < arr.size()){
            flag1 = true;
            int val = arr[i];
            if(val == 0){
                if(flip) break;
                else flip = true;
            }
            i++;
        }
        ans = max(ans, i- (j+1));
        //Release till you release one 0
        while(j < i){
            flag2 = true;
            int val = arr[++j];
            if(val == 0){
                flip = false;
                break;
            }
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
