//Floor of X -> element just greater than X -> Minimim of all greater elements than X
//Ceil of X -> element just smaller than X  -> Maximum of all smaller elements than X

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

static int floor = INT_MIN, ceil = INT_MAX;
void floorCeil(Node *root, int data){
    if(root->data < data && root->data > floor){
        floor = root->data;
    }
    else if(root->data > data && root->data < ceil){
        ceil = root->data;
    }
    for(Node *child : root->children){
        floorCeil(child, data);
    }
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
    floorCeil(root, 10);
    if(floor == INT_MIN)
        cout<<"Floor : "<<INT_MIN<<endl;
    else
        cout<<"Floor : "<<floor<<endl;

    if(ceil == INT_MAX)
        cout<<"Ceil : "<<INT_MAX<<endl;
    else
        cout<<"Ceil : "<<ceil<<endl;
    return 0;
}