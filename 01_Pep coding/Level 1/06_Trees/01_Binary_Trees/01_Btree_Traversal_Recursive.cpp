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

// Recursive Method
void preOrderTraversal(Node *ptr){
    if(ptr == NULL)
        return;
    cout<<ptr->data<<" ";
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

void inOrderTraversal(Node *ptr){
    if(ptr == NULL)
        return;
    inOrderTraversal(ptr->left);
    cout<<ptr->data<<" ";
    inOrderTraversal(ptr->right);
}

void postOrderTraversal(Node *ptr){
    if(ptr == NULL)
        return;
    postOrderTraversal(ptr->left);
    postOrderTraversal(ptr->right);
    cout<<ptr->data<<" ";
}

void levelOrderTraversal(Node *root, queue <Node*> q){
    if(root == NULL || q.empty())
        return;
    Node *temp = q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left)
        q.push(temp->left);
    if(temp->right)
        q.push(temp->right);
    levelOrderTraversal(temp, q);
}
/*
     4
    / \
   1   6
  / \
 5   2 
*/

int main(){
    Node *root = new Node(4);
    Node *p2 = new Node(1);
    Node *p3 = new Node(6);
    Node *p4 = new Node(5);
    Node *p5 = new Node(2);

    root->left  = p2;
    root->right  = p3;
    p2->left = p4;
    p2->right = p5;

    cout<<"Pre Order : ";    
    preOrderTraversal(root);   
    cout<<endl;

    cout<<"In Order : ";     
    inOrderTraversal(root);    
    cout<<endl;

    cout<<"Post Order : ";   
    postOrderTraversal(root);  
    cout<<endl;

    queue<Node*> q; q.push(root);
    cout<<"Levdl Order : ";   
    levelOrderTraversal(root, q);  
    cout<<endl;
    return 0;
}