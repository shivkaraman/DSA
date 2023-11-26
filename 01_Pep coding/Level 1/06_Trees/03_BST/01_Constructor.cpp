
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
    
    return 0;
}