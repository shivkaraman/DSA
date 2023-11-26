// check if the tree is a Binary Search Tree (BST) as well. In a BST every node has a value greater than all 
// nodes on it's left side and smaller value than all node on it's right side.
// https://www.youtube.com/watch?v=kMrbTnd5W9U&list=PL-Jc9J83PIiHYxUk8dSu2_G7MR1PaGXN4&index=49

#include <iostream>
#include <algorithm>
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
    int i=1;
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

class BSTpair{
    public : 
        bool isbst;
        int min, max;
};

BSTpair isBST(Node *root){
    if(root == NULL){
        BSTpair base;
        base.isbst = 1;
        base.min = INT_MAX;
        base.max = INT_MIN;
        return base;
    }

    BSTpair lp = isBST(root->left);
    BSTpair rp = isBST(root->right);

    BSTpair myPair;
    // Is tree BST = left sub tree is bst  AND right sub tree is bst AND current node satisfies conditon of bst
    //Current node condition -> if root->data >= LeftMax  then root->data is greater than the whole left subtree
    //                          if root->data <= RightMin then root->data is smaller than the whole right subtree
    myPair.isbst = lp.isbst && rp.isbst && (root->data > lp.max && root->data < rp.min);
    //We need only LMAX and RMIN, but y are we calculating all RMAX, RMIN, LMAX and LMIN?
    //We need to know LeftMax and RightMin, but we donno if we are in right subrtree or in the left subtree
    //If current is a child, then its parent needs Max if current is a left child and Min if current is a right child
    //so we calculate both min and max

    //Another reason is that, to check if current node is a BST, we need only RMIN and LMAX, but to calculate my min and max
    //i need RMAX and LMIN. I should calculate my min and max coz my parent needs it 
    myPair.min  = min (root->data, min(lp.min, rp.min));
    myPair.max = max (root->data, max(lp.max, rp.max));
    return myPair;
}

/*
NOT BST
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
              /\    \  
            30 51    70
BST
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
              /    \  
            30      70
*/  
int main(){
    // vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 51, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(vec);
    BSTpair ans = isBST(root);
    cout<<ans.isbst<<endl;
    return 0;
}