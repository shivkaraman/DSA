/*
     4
    / \
   1   6
  / \
 5   2 
*/

#include <iostream>
#include <stack>
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

//Creating tree when all nodes are given in preOrder
Node* buildTreePreorder(vector<int> vec){    //https://www.pepcoding.com/resources/online-java-foundation/binary-tree/binary-tree-constructor/video
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
  
int main(){
    vector<int> vec = {4, 1, 5, NULL, NULL, 2, NULL, NULL, 6, NULL, NULL};
    Node *root = buildTreePreorder(vec);
    cout<<"Pre Order : ";    preOrderTraversal(root);   cout<<endl;
    cout<<"In Order : ";     inOrderTraversal(root);    cout<<endl;
    cout<<"Post Order : ";   postOrderTraversal(root);  cout<<endl;
    return 0;
}