// 1. You are given a partially written BinaryTree class.
// 2. Create a new node for every node equal in value to it and inserted between itself and it's left child. 
//    Check question video for clarity.
// 3. Input and Output is managed for you.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public : 
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }   
};

Node* createTree(vector<int> vec){
    stack<pair<Node*, int>> s;
    Node *root = new Node(vec[0]);
    s.push({root, 1});
    int i = 1;
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){
            s.top().second++;
            if(vec[i] != 0){
                temp.first->left = new Node(vec[i]);    
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){
            s.top().second++;
            if(vec[i] != 0){
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

void cereateLeftClonedTree(Node *root){
    if(root == NULL)
        return;
    Node *temp = new Node(root->data);
    temp->left = root->left;
    root->left = temp;
    cereateLeftClonedTree(temp->left);  //Note : we use temp->left here
    cereateLeftClonedTree(root->right);
}

void preOrderTraversa(Node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrderTraversa(root->left);
    preOrderTraversa(root->right);
}
/*
                50  
               /  \
            25      75
            / \     / \ 
          12  37  62  87
              /\   /\  
            30 40 60 70
*/  

int main(){
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL,40, NULL, NULL, 75, 62, 60, NULL, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(vec);

    preOrderTraversa(root);
    cout<<endl;

    cereateLeftClonedTree(root);
    
    preOrderTraversa(root);
    cout<<endl;
    return 0;
}