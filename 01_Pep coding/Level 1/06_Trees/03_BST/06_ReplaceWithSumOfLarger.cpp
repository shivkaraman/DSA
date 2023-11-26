//  replace a node's value with sum of all nodes greater than it.
// https://www.youtube.com/watch?v=MLff3CxNVTc&list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2&index=10

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

static int sum = 0;
Node* replace(Node *root){
    if(root == NULL)
        return NULL;
    replace(root->right);

    int temp = root->data;
    root->data = sum;
    sum += temp;
    
    replace(root->left);
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
Replace 87-> 0
        62-> 75 + 87
        75-> 87
        .
        .
        12-> 37+25+50+75+62+87
*/  
int main(){
    vector<int> vec = {12, 25, 37, 50, 62, 75, 87};
    Node *root = createTree(vec, 0, vec.size() - 1);
    root = replace(root);
    levelOrder(root);
    return 0;
}