// https://www.youtube.com/watch?v=ssL3sHwPeb4 --> Striver

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

//Striver Code
class BSTIterator {
        stack<Node*> s;
        bool reverse = true; 
        void pushAll(Node *node) {
            while(node != NULL) {
                 s.push(node);
                 if(reverse == true) {
                     node = node->right; 
                 } else {
                     node = node->left; 
                 }
            }
        }
    public:
        BSTIterator(Node *root, bool isReverse) {
            reverse = isReverse; 
            pushAll(root);
        }

        // return whether we have a next element in inorder
        bool hasNext() {
            return !s.empty();
        }

        //return the next element in inorder
        int next() {
            Node *tmpNode = s.top();
            s.pop();
            if(!reverse) 
                pushAll(tmpNode->right);
            else 
                pushAll(tmpNode->left);
            return tmpNode->data;
        }
};


void targetSumPair(Node* root, int target) {   // T = O(n) S = O(h) = O(logn)
    if(!root) 
        return; 
    BSTIterator l(root, false);   //--> TO give next element in inorder traversal  
    BSTIterator r(root, true);   //--> TO give next element in reverse inorder traversal
    
    int left = l.next();    
    int right = r.next(); 
    while(left < right) {
        if(left + right == target){ 
            cout << left << " " << right << endl;
            left = l.next(); 
            right = r.next(); 
        }
        else if(left + right < target) 
            left = l.next(); 
        else 
            right = r.next(); 
    }
}
/*
                50  
               /   \
            25      75
            / \     / \ 
          12  38  62  87 
*/  
int main(){
    vector<int> vec = {12, 25, 38, 50, 62, 75, 87};
    Node *root = createTree(vec, 0, vec.size() - 1);
    targetSumPair(root, 100);
    return 0;
}