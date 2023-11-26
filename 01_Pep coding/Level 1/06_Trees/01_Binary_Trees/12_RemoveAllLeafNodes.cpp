//Remove all leaf nodes

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

Node* remove_All_Leaf_Nodes(Node *root){
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    root->left = remove_All_Leaf_Nodes(root->left);
    root->right = remove_All_Leaf_Nodes(root->right);
    return root;
}

void preOrderTraversal(Node *ptr){
    if(ptr == NULL)
        return;
    cout<<ptr->data<<" ";
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}
/*
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
              /    \  
            30      70
*/  

int main(){
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(vec);
    preOrderTraversal(root);
    cout<<endl;

    // root = remove_All_Leaf_Nodes(root);
    remove_All_Leaf_Nodes(root);
    preOrderTraversal(root);
    cout<<endl;
    return 0;
}