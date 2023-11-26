
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

//Faith -> all the children know to get their linear tree and gives tail of the tree
// https://www.youtube.com/watch?v=D5RYXVgJ5NM&list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_&index=25
Node* linearise(Node *root){
    if(root->children.size() == 0){
        return root;
    }
    Node *lastChildTail = linearise(root->children[root->children.size()-1]); // Linearises subtree of last child and give its tail
    while(root->children.size() > 1){                                         
        Node *lc = root->children[root->children.size()-1];     
        root->children.pop_back();

        Node *slc = root->children[root->children.size()-1];    
        Node*slt = linearise(slc);          

        slt->children.push_back(lc);
    }
    return lastChildTail;
}

void preOrder(Node *root){
    cout<<root->data<<" ";
    for(Node *child : root->children){
        preOrder(child);
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
    linearise(root);
    preOrder(root);
    return 0;
}