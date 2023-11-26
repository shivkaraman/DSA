// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. You are required to print all elements of a2 which are also present in a1 (in order of their occurence in a2). Make sure to not print duplicates (a2 may have same value present many times).

// Constraints
// 1 <= n1, n2 <= 100
// 0 <= a1[i], a2[i] < 10
// Time complexity should be O(n)#include <iostream>

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n1,n2;
    cin >> n1;
    int arr1[n1];
    
    unordered_map<int, int> mp;
    for (int i = 0; i < n1; i++) {
        cin>>arr1[i];
        mp[arr1[i]];
    }
    cin >> n2;
    int arr2[n2];

    int size = mp.size();
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
        mp.erase(arr2[i]);
        if(mp.size() < size){
        cout << arr2[i] << endl;
        size--;
        }
    }
}