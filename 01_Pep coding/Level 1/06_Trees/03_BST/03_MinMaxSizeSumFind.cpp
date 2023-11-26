
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

int size(Node *root){
    static int Size = 0;
    if(root == NULL)
        return 0;
    Size++;
    size(root->left);
    size(root->right);
    return Size;
}

int MAX(Node *root){
    if(root->right == NULL)
        return root->data;
    int max = MAX(root->right);
    return max;
}

int MIN(Node *root){
    if(root->left == NULL)
        return root->data;
    int min = MIN(root->left);
    return min;
}

int sum(Node *root){
    if(root == NULL)
        return 0;
    static int Sum = 0;
    Sum += root->data;
    sum(root->right);
    sum(root->left);
    return Sum;
}

bool search(Node *root, int data){
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    if(data > root->data){
        if(search(root->right, data))
            return true;
    }
    else{
        if(search(root->left, data))
            return true;
    }
    return false;
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
    cout<<"Size : "<<size(root)<<endl;
    cout<<"Max : "<<MAX(root)<<endl;
    cout<<"Min : "<<MIN(root)<<endl;
    cout<<"Sum : "<<sum(root)<<endl;
    if(search(root, 6))
        cout<<"Found"<<endl;
    else
        cout<<"Nor found"<<endl;
    return 0;
}