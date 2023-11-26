// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. The array is nearly sorted. Every element is at-max displaced k spots left or right to it's position in the sorted array. 
//    Hence it is being called k-sorted array.
// 4. You are required to sort and print the sorted array.
// https://www.youtube.com/watch?v=pptk8cUHHUg&list=PL-Jc9J83PIiHq5rMZasunIR19QG3E-PAA&index=14
// Documentation : https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/sort_a_k_sorted_array/topic

#include <bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k){
	priority_queue<int, vector<int>, greater<int>> pq;	//Min Heap
	int i;
	for(i = 0; i <= k; i++){
		pq.push(arr[i]);
	}
	for(i = k + 1; i < n; i++){
		cout<<pq.top()<<endl;
		pq.pop();
		pq.push(arr[i]);
	}
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++){
		int data;
		cin >> data;
		arr[i] = data;
	}
	int k;
	cin >> k;
	sortK(arr, n, k);
	return 0;
}