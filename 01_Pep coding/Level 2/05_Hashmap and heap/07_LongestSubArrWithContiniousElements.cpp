// https://nados.io/question/largest-subarray-with-contiguous-elements?zen=true
// https://www.youtube.com/watch?v=37MdIo-MaSU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=7
//In an array, if a subarray [say from idx i to j] contains continious elements, then it follows a property
// max-min = j - i

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> &arr){
    int maxL = 0;
    for(int i = 0; i < arr.size()-1; i++){
        int mx = arr[i];
        int mn = arr[i];
        unordered_set<int> cd; //Check duplicacy
        cd.insert(arr[i]);
        for(int j = i+1; j < arr.size(); j++){
            if(cd.find(arr[j]) != cd.end()) break;

            cd.insert(arr[j]);
            mx = max(mx, arr[j]);
            mn = min(mn, arr[j]);

            if(mx-mn == j-i) maxL = max(maxL, j-i+1);
        }
    }
    return maxL;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solution(arr) << endl;
}