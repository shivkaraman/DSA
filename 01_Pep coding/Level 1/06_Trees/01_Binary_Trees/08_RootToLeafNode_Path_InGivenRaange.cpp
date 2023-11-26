// 1. You are given a BinaryTree.
// 2. You are given a value lo and a value hi
// 3. Print all paths from root to leaves which have sum of nodes in range from lo to hi (both inclusive). 
//    The elements in path should be separated by spaces. Each path should be in a separate line.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public : 
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left = right= NULL;
        }
};

Node* createTree(vector<int> vec){
    stack<pair<Node*, int>> s;
    Node *root = new Node(vec[0]);
    s.push({root, 1});
    int i = 1;
    while(!s.empty()){
        pair<Node*, int> p = s.top();
        if(p.second == 1){
            s.top().second++;
            if(vec[i] != 0){
                p.first->left = new Node(vec[i]);
                s.push({p.first->left, 1});
            }
            i++;
        }
        else if(p.second == 2){
            s.top().second++;
            if(vec[i] != 0){
                p.first->right = new Node(vec[i]);
                s.push({p.first->right, 1});
            }
            i++;
        }
        else{
            s.pop();
        }
    }
    return root;
}

void pathToLeafFromRoot(Node* node, string path, int sum, int lo, int hi){
    if(node == NULL)
        return;
    if(node->left == NULL && node->right == NULL){
        sum += node->data;
        if(sum >= lo && sum <= hi){
            cout<<path + to_string(node->data)<<endl;
        }
        return;
    }
    pathToLeafFromRoot(node->left, path + to_string(node->data) + " ", sum + node->data, lo, hi);
    pathToLeafFromRoot(node->right,path + to_string(node->data) + " ", sum + node->data, lo, hi);
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
    int low, high;
    cin>>low>>high;
    pathToLeafFromRoot(root, "", 0, low, high);
    return 0;
}