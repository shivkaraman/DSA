// Add a new node with given data to the tree and return the new root.

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

Node* createTree(vector<int> vec, int l, int h){    
    if(l > h)   
        return NULL;
    int mid = (l + h)/2;
    int data = vec[mid];
    Node *lt = createTree(vec, l, mid - 1);
    Node *rt = createTree(vec, mid + 1, h);
    Node *root = new Node(data);
    root->left = lt;
    root->right = rt;
    return root;
}

Node* AddNode(Node *root, int data){
    if(root == NULL){
        Node *newNode = new Node(data);
        return newNode;
    }
    if(data < root->data){
        root->left = AddNode(root->left, data);
    }
    if(data > root->data){
        root->right = AddNode(root->right, data);
    }
    return root;
}

void inOrder(Node *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
/*
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
*/  
int main(){
    vector<int> vec = {12, 25, 37, 50, 62, 75, 87};
    Node *root = createTree(vec, 0, vec.size() - 1);
    cout<<"Before adding : "; inOrder(root);
    AddNode(root, 60);
    cout<<endl<<"After adding : "; inOrder(root);
    return 0;
}