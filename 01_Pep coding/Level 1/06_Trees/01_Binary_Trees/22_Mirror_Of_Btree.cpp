
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

Node* Mirror(Node *root){ //New tree
    if(root == NULL)
        return NULL;
    Node *Mroot = new Node(root->data);
    Mroot->left = Mirror(root->right);
    Mroot->right = Mirror(root->left);
    return Mroot;
}

void Mirror2(Node *root){ //Tree itself is inverted
    if(root == NULL)
        return;
    Mirror2(root->left);
    Mirror2(root->right);
    swap(root->left, root->right);
}

void levelOrderTraversal(Node *root){
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
          12  37   62  87
              /\   / \  
            30 51 100  70
*/  
int main(){
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 51, NULL, NULL, 75, 62, 100, NULL, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(vec);
    cout<<"Btree : "<<endl; levelOrderTraversal(root);
    Node *Mroot = Mirror(root);
    cout<<"Mirror Btree : "<<endl; preOrderTraversal(Mroot);//levelOrderTraversal(Mroot);

    // Mirror2(root);
    // cout<<"Btree : "<<endl; levelOrderTraversal(Mroot);
    return 0;
}