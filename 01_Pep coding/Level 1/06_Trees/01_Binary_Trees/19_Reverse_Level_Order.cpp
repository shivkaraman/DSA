
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public : 
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

Node* createTree(vector<int> vec){    
    Node *root = new Node(vec[0]);

    pair<Node*, int> p = {root, 1};
    stack<pair<Node*, int>> s;
    s.push(p);

    for(int i=1; s.size()>0;){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){   //New node to left
            s.top().second++;
            if(vec[i] != 0/*NULL*/){
                temp.first->left = new Node(vec[i]);
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){ //New node to right
            s.top().second++;
            if(vec[i] != 0/*NULL*/){
                temp.first->right = new Node(vec[i]);
                s.push({temp.first->right, 1});
            }
            i++;
        }
        else{
            s.pop();
        }
    }
    return root;
}

void ReverseLevelOrder(Node *root){
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->right)     //Note we first check right and then left
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        s.push(temp->data); //Push data into stack
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
/*
                50  
               /   \
            25      75
            / \     / 
          12  37   62  
              /\   /\  
            30 51 60 70
*/ 
int main(){
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 51, NULL, NULL, 75, 62, 60, NULL, NULL, 70, NULL, NULL, NULL};
    Node *root = createTree(vec);
    ReverseLevelOrder(root);
    return 0;
}