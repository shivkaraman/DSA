//A node can have 0, 1 or 2 children-> Hence we hust cant remove the node coz Tree present below the node will be effective
// 0 child --> remove child
// 1 child --> link parent of node to child of node to be deleted and delete the node
// 2 children --> replace node by max element of left sub tree of current node --> We chose max of left sub tree coz WKT
//                 all elements in left subtree are lesser than the current element , hence if we replace current node by leftMax
//                 all elements on left subtree remain lesser than current node

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

Node* createTree(vector<int> vec, int l, int h){    
    if(l > h)   
        return NULL;
    int mid = (l + h)/2;
    int data = vec[mid];
    Node *lt = createTree(vec, l, mid - 1);
    Node *rt = createTree(vec, mid + 1, h);
    Node *root = new Node(data);
    root->left = lt;
    root->right = rt;
    return root;
}

int MAX(Node *root){
    if(root->right == NULL)
        return root->data;
    int max = MAX(root->right);
    return max;
}

Node* removeNode(Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        //0 Child
        if(root->right == NULL && root->left == NULL){
           delete root;
           root = NULL;
           return NULL;
        }
        //1 Child
        else if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right != NULL && root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //2 children
        else{
            int max = MAX(root->left);
            root->data = max;
            root->left = removeNode(root->left, max);
            return root;
        }
    }
    else if(data < root->data)
        root->left = removeNode(root->left, data);
    else
        root->right = removeNode(root->right, data);
    return root;
}

void levelOrder(Node *root){
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node *temp = q.front();
            q.pop();
            //print cvurrent child
            cout<<temp->data<<" ";
            //At level 'l' add nodes of 'l+1'th level to queue
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        cout<<endl;
    }
}
/*
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
                      /
                    77
*/  
int main(){
    vector<int> vec = {12, 25, 37, 50, 62, 75, 77, 87};
    Node *root = createTree(vec, 0, vec.size() - 1);
    root = removeNode(root, 77);
    levelOrder(root);
    return 0;
}