/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers, representing n elements.
3. You are required to find the maximum sum of a subsequence with no adjacent elements.

Sample Input
6
5
10
10
100
5
6

Sample Output
116
*/

#include <iostream>
#include <vector>
using namespace std;
/*
Storage-> 2 1D arrays
Meaning-> inc[i]-> Stores max sum non adjascent elements ending with //* ith element INCLUDED
          exc[i]-> Stores max sum non adjascent elements ending with //* ith element NOT INCLUDED
Direction->0->n 
Traverse and solve: 
            Initialise inc[1] = arr[0] and exc[1] = 0
            inc[i] has only option ie inc[i] = exc[i] + arr[i] because//* if current element has to be included, prev element has to be excluded
            exc[i], since curr element cannot be included, we can choose either the sum till prev element where prev element was not included or prev element included WHICHEVER IS GREATEST ie max(inc[i-1], exc[i-1]) //* ie if curr element is excluded, prev element can be excluded or included
             
https://www.youtube.com/watch?v=VT4bZV24QNo&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=22
*/
int maxSum(vector<int> arr){
    int inc = arr[0];
    int exc = 0;
    for(int i = 1; i < arr.size(); i++){
        int ninc = exc + arr[i];
        int nexc = max(inc, exc);
        inc = ninc;
        exc = nexc;
    }
    return max(inc, exc);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxSum(arr) << endl;

    return 0;
}

