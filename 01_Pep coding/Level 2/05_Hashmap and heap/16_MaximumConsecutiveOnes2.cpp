// maximum number of consecutive 1's in the given array if you can flip at most K zeroes.
// https://nados.io/question/maximum-consecutive-ones-2?zen=true


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> &arr, int k) {
    int ans = 0, i = 0, j = -1;
    int flip = 0;
    while(true){
        bool flag1 = 0, flag2 = 0;
        //Acquire till you find k+1th zero
        while(i < arr.size()){
            flag1 = true;
            int val = arr[i];
            if(val == 0){
                flip++;
                if(flip > k) break;
            }
            i++;
        }
        flip--;
        ans = max(ans, i- (j+1));
        if(i == arr.size()) break;
        //Release till you release one 0
        while(j < i){
            flag2 = true;
            int val = arr[++j];
            if(val == 0){
                flip--;
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
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    cout << solution(arr, k);
}
