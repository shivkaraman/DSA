// Check if the tree is balanced. 
// A binary tree is balanced if for every node the gap between height's of it's left and right subtree is not more than 1.

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

pair<bool, int> isBalanced(Node *root){
    if(root == NULL)
        return {true, -1};

    //pair<isBalanced, height>
    pair<bool, int> l = isBalanced(root->left);
    pair<bool, int> r = isBalanced(root->right);

    pair<bool, int> balanced;
    balanced.second = max(l.second, r.second) + 1;
    balanced.first = l.first && r.first && abs(l.second - r.second) <= 1;

    return balanced;
}
/*
Balanced
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
              /    \  
            30      70
Not balanced
                50  
               /   \
            25      75
            / \     / 
          12  37  62  
              /\   /\  
            30 51 60 70
*/  
int main(){
    // vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 51, NULL, NULL, 75, 62, 60, NULL, NULL, 70, NULL, NULL, NULL};
    Node *root = createTree(vec);
    pair<bool, int> ans = isBalanced(root);
    cout<<ans.first<<endl;
    return 0;
}