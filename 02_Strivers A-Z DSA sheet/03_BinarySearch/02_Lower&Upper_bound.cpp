/*
Lower Bound
For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' is not less than 'x'
If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.

Upper Bound
The upper bound in a sorted array is the index of the first value that is greater than a given value. 
If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
We are using 0-based indexing.


In simple words 
* Lower bound is index of element that is just >= given element 
* Upper bound is the index of element > given element

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) { //We have done reverse of normal binary search while assigning i=mid+ and j=mid-1
	int i = 0, j = n-1, ans = -1;
	while(i <= j){
		int mid = (i+j+1)/2;
		if(arr[mid] < x)
			i = mid+1;
		else{
			j = mid-1;
			ans = mid;
		}
	}
	if(ans == -1 && x > arr[n-1])
		return n;
	return ans;
}

int upperBound(vector<int> arr, int n, int x) { 
	int i = 0, j = n-1, ans = n;
	while(i <= j){
		int mid = (i+j+1)/2;
		if(arr[mid] <= x)
			i = mid+1;
		else{
			j = mid-1;
			ans = mid;
		}
	}
	
	return ans;
}

int main(){
    vector<int> arr = {1,4,7,8,10};
    cout << upperBound(arr, 5, 7);
    return 0;
}