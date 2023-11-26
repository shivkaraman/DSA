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
void printInRange(Node *root, int l, int h){
    if(root == NULL)
        return;
    if(root->left && root->left->data >= l)
        printInRange(root->left, l, h);

    if(root->data <= h && root->data >= l)
        cout << root->data << " ";
    
    if(root->right && root->right->data <= h)
        printInRange(root->right, l, h);
}

/*
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87

*/  
int main(){
    vector<int> vec = {12, 25, 37, 50, 62, 75, 87};
    Node *root = createTree(vec, 0, vec.size() - 1);

    int l, h;
    cin >> l >> h;

    printInRange(root, l, h);
    return 0;
}