
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

Node* createTree(vector<int> vec){    
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
  
int leafCount(Node *root){
    queue<Node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(!temp->right && !temp->left)
            count++;
        else{
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return count;
}

int leafCount2(Node *root){
    if(root == NULL)
        return 0;
    int lc = leafCount2(root->left);
    int rc = leafCount2(root->right);
    int count = lc + rc;
    if(!root->left && !root->right) 
        count++;
    return count;

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
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 51, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, NULL};
    Node *root = createTree(vec);
    // cout<<leafCount(root)<<endl;
    cout<<leafCount2(root)<<endl;
    return 0;
}