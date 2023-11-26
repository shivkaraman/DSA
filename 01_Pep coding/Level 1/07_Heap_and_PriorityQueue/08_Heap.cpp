/*
    if current node -> i
    parent = (i-1)/2
    left child = 2*i+1
    right child = 2*i+2
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class heap{
    public :
        int *arr;
        int capacity;   //Capacity of heap(array)
        int size;       //No of elements in heap
        bool heapType;  //Min heap(0) or max heap(1)
};

heap* createHeap(int capacity, bool heapType){
    heap *h = new heap();
    h->capacity = capacity;
    h->size = 0;
    h->arr = new int[h->capacity];
    h->heapType = heapType;
    return h;
}

int leftChild(heap *h, int i){
    if(2*i + 1 < h->size){
        return 2*i + 1;
    }
    return -1;
}

int rightChild(heap *h, int i){
    if(2*i + 2 < h->size){
        return 2*i + 2;
    }
    return -1;
}

int parent(heap *h, int i){
    if((i-1)/2 < 0)
        return -1;
    return (i-1)/2;
}

int getMax(heap *h){
    if(h->size != 0)
        return h->arr[0];
    return -1;
}

void resize(heap *h){
    h->capacity *=2;
    h->arr = (int*)realloc(h->arr, h->capacity * sizeof(int));
}

void display(heap *h){
    //pair <element, index>
    queue<pair<int, int>> q;
    q.push({h->arr[0], 0});
    while(!q.empty()){
        int size = q.size();
        for(int x = 0; x <size; x++){
            pair<int, int> p = q.front();
            q.pop();
            cout<<p.first<<" ";
            int l = leftChild(h, p.second);
            int r = rightChild(h, p.second);
            if(l != -1)
                q.push({h->arr[l], l});
            if(r != -1)
                q.push({h->arr[r], r});
        }
        cout<<endl;
    }

}

void percolateDown(heap *h, int i){
    int l = leftChild(h, i);
    int r = rightChild(h, i);
    int maxIdx = i;
    if(l != -1 && h->arr[l] > h->arr[i]){
        maxIdx = l;
    }
    if(r != -1 && h->arr[r] > h->arr[maxIdx]){
        maxIdx = r;
    }
    if(maxIdx != i)
        swap(h->arr[i], h->arr[maxIdx]);
    else 
        return;
    percolateDown(h, maxIdx);
}

void percolateUp(heap *h, int i){
    if(i <= 0)
        return;
    int p = parent(h, i);
    if(p != -1 && h->arr[p] < h->arr[i])
        swap(h->arr[p], h->arr[i]);
    percolateUp(h, p);
}

void insert(heap *h, int data){ //O(logn)
    if(h->size == h->capacity){
        resize(h);
    }
    h->size++;
    int i = h->size - 1;
    h->arr[i] = data;
    percolateUp(h, i);
}

int deleteMax(heap *h){ //O(logn)
    int mx = h->arr[0];
    h->arr[0] = h->arr[h->size-1];
    h->size--;
    percolateDown(h, 0);
    return mx;
}

void heapify(heap *h){  //O(n)
    for(int i = h->size - 1; i >= 0; i--){
        percolateDown(h, i);
    }
}

int main(){
    heap *h;
    h = createHeap(5, 1);
    // vector<int> vec = {10, 20, 15, 30, 40}; 
    // for(int i = 0; i < vec.size(); i++){     //O(n logn)
    //     insert(h, vec[i]);
    // }

    // h->arr[0] = 10;
    // h->arr[1] = 20;
    // h->arr[2] = 15;
    // h->arr[3] = 30;
    // h->arr[4] = 40;
    // h->size = 5;
    // heapify(h);     // O(N)

    // cout<<"Heap"<<endl;
    // display(h);
    // deleteMax(h);
    // cout<<endl<<"Heap"<<endl;
    // display(h);
    // return 0;

     while (1) {
        string str;
        getline(cin, str);
        if (str[0] == 'a') {
          string num = str.substr(4, str.length());
          int val = stoi(num);
          insert(h, val);
        } else if (str[0] == 'r') {
          int val = deleteMax(h);
          if (val != -1) {
            cout << val << endl;
          }
        } else if (str[0] == 'p') {
          int val = getMax(h);
          if (val != -1) {
            cout << val << endl;
          }
        } else break;
  }
}