
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int* NGETR(int *arr, int n){
    stack<int> s;
    int *ans = new int[n];
    ans[n-1] = -1;
    s.push(arr[n-1]);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && arr[i] >= s.top()){   //* Pop all smaller elements to right(which is stored in stack)
            s.pop();
        }
        if(s.empty())                             //* IF stack is empty, it means there is no element greater than current element
            ans[i] = -1;
        else                                      //* If not empty, it means there is an element greater than current element
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main(){
    
    return 0;
}