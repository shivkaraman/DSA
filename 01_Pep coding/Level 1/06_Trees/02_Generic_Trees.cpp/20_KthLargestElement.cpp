
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node{
    public :
        int data;    
        vector<Node*> children;
        Node(int data){
            this->data = data;
        }
};

Node* createTree(vector<int> vec){
    stack<Node*> s;
    Node *root = new Node(vec[0]);
    s.push(root);
    int i = 1;
    while(!s.empty()){
        if(vec[i] == -1){
            s.pop();
        }
        else{
            Node *child = new Node(vec[i]);
            s.top()->children.push_back(child);
            s.push(child);
        }
        i++;
    }
    return root;
}

static int floor = INT_MIN;
void Floor(Node *root, int data){
    if(root->data < data && root->data > floor){
        floor = root->data;
    }
    for(Node *child : root->children){
        Floor(child, data);
    }
}

//Floor of INT_MAX -> Largest element of tree
//Floor of largest element -> 2nd largest
//repeat k times -> kth largest element
int kthLargest(Node *root, int k){
    int factor = INT_MAX;
    for(int i = 0; i<k; i++){
        Floor(root, factor);
        factor = floor;
        floor = INT_MIN;
    }
    return factor;
}
/*
              10
           /   |  \
         20   30  40
        /\   / | \  \
      50 60 70 80 90 100
               /\
             110 120
*/
int main(){
    vector<int> vec = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(vec);
    int k;
    cin>>k;
    cout<<kthLargest(root, k)<<endl;
    return 0;
}