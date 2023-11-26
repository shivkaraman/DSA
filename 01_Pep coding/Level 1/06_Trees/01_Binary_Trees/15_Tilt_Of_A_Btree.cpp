// "sum" of a node is the absolute value of difference between sum of nodes in it's left subtree and right subtree
// "sum" of the whole tree is represented as the sum of "sum"s of all it's nodes.

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
            left = right = NULL;
        }
};

Node* createTree(vector<int> pre){
    stack<pair<Node*, int>> s;
    Node *root = new Node(pre[0]);
    s.push({root, 1});
    int i = 1;
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){
            s.top().second++;
            if(pre[i] != 0){   
                temp.first->left = new Node(pre[i]);
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){
            s.top().second++;
            if(pre[i] != 0){  
                temp.first->right = new Node(pre[i]);
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

static int Tilt = 0;
int sum(Node *root){
    if(root == NULL)
        return 0;
    int ls = sum(root->left);  //Returns sum of all elements in left subtree
    int rs = sum(root->right); //Returns sum of all elements in right subtree

    int localTilt = abs(ls - rs);//Tilt of node
    Tilt += localTilt;           //Tilt of whole tree
    
    int totSum = ls + rs + root->data; 
    return totSum;
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
    sum(root);
    cout<<Tilt<<endl;
    return 0;
}