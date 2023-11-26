#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

int maxElement(Node *root){
    if(root == NULL)
        return 0;
    int lm = maxElement(root->left);
    int rm = maxElement(root->right);
    return max(root->data, max(lm, rm));
}
// Without recursion, traverse through the btree
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
    cout<<maxElement(root)<<endl;
    return 0;
}