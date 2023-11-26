
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
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
//https://www.youtube.com/watch?v=0PBC_EEBHGg&list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_&index=22
void removeLeaves(Node *parent){
    for(int i = parent->children.size()-1; i >= 0; i--){
        Node *child = parent->children[i];
        if(child->children.size() == 0){
            remove(parent->children.begin(), parent->children.end(), child);
            parent->children.resize(parent->children.size()-1);
            // for(int j = i; j < parent->children.size(); j++){
            //     parent->children[i] = parent->children[i+1];
            // }
            // parent->children.pop_back();
        }
    }
    for(Node *child : parent->children){
        removeLeaves(child);
    }
}

void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            cout<<q.front()->data<<" ";
            for(Node *child : q.front()->children){
                q.push(child);
            }
            q.pop();
        }
        cout<<endl;
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
    levelOrder(root);
    removeLeaves(root);
    cout<<endl<<"New Tree"<<endl;
    levelOrder(root); 
    return 0;
}