// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are given a number k.
// 4. You are required to find and print the k largest elements of array in increasing order.
// https://www.youtube.com/watch?v=taL2G6jDLog&list=PL-Jc9J83PIiHq5rMZasunIR19QG3E-PAA&index=12

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int data;
        cin >> data;
        vec.push_back(data);
    }
    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> pq;  //Min heap
    for(int i = 0; i<n; i++){
        if(i < k)
            pq.push(vec[i]);
        else{
            if(pq.top() < vec[i]){
                pq.pop();
                pq.push(vec[i]);
            }
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}