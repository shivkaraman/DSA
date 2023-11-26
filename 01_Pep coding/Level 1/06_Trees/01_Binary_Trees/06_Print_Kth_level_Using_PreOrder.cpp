//Print kth levek using only pre order traversal

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

void printKthlevel(Node *root, int K){
    if(root == NULL || K<0)
        return;
    if(K == 0)  //K is ZERO only when we have reached Kth level
        cout<<root->data<<" ";
    printKthlevel(root->left, K-1);   //Kth level is (K-1) levels away from root->left
    printKthlevel(root->right, K-1);  //Kth level is (K-1) levels away from root->right
}

/*
                50  
               /  \
            25     75
            / \    / \
          12  37 62  87
              /   \  
            30    70
*/  
int main(){
    vector<int> pre = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(pre);
    int k;
    cin>>k;
    printKthlevel(root, k);
    return 0;
}