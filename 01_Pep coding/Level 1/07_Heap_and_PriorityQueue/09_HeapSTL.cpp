
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//By default, C++ creates a max heap
// Max Heap : priority_queue(int , container)
// Min Heap : priority_queue(int , container, greater<int>)


int main(){
    vector<int> vec = {10, 20, 15, 30, 40}; 
    priority_queue<int, vector<int>> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(40);
    return 0;
}