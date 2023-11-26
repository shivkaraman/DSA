//Transform a left cloned tree to a normaltree

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

void LeftClonedTreeToNormal(Node *root){
    if(root == NULL)
        return;
    Node *temp = root->left;
    root->left = temp->left;
    delete temp;
    LeftClonedTreeToNormal(root->left);
    LeftClonedTreeToNormal(root->right);
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
              /     \  
            30       70
*/  

int main(){
    vector<int> vec = {50, 50, 25, 25, 12, 12, NULL, NULL, NULL, NULL, 37, 37, 30, 30, NULL, NULL, NULL, NULL, NULL, NULL, 
                       75, 75, 62, 62, NULL, NULL, 70, 70, NULL, NULL, NULL, NULL, 87, 87, NULL, NULL, NULL};
    Node *root = createTree(vec);
    preOrderTraversa(root);
    cout<<endl;

    LeftClonedTreeToNormal(root);
    preOrderTraversa(root);
    cout<<endl;
    return 0;
}