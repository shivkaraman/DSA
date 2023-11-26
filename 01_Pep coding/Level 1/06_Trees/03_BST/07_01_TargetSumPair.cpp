// ou are given a value. You are required to print all pair of nodes which add up to the given value. 
// Make sure all pairs print the smaller value first and avoid duplicacies.

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

bool search(Node *root, int data){
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    if(data < root->data){
        if(search(root->left, data))
            return true;
    }
    if(data > root->data){
        if(search(root->right, data))
            return true;
    }
    return false;
}

//Approach -> to find complement of current node and search if its present and print it -> T=O(nh)=O(n logn), S=O(h)=O(logn)
void targetSumPair(Node *root, Node *node, int target){
     if(node == NULL)
        return;
    targetSumPair(root, node->left, target);
    int comp = target - node->data;
    if(node->data < comp){      // This condition is necessey coz 25+75 = 100 && 75+25 = 100. to avoid printing both we use this. 
        if(search(root, comp))  // We can use node->data > comp, but we are suppose to print smaler value first
            cout<<node->data<<" "<<comp<<endl;
    }
    targetSumPair(root, node->right, target);
}

//Approach 2-> Get inorder (gives all element in sorted order) and check pair sum
void travelNFill(Node *root, vector<int> &vec){
    if(root == NULL)
        return;
    travelNFill(root->left, vec);
    vec.push_back(root->data);
    travelNFill(root->right, vec);
}

void targetSumPair2(Node *root, int target){    //T=S=O(n)
    vector<int> vec;
    travelNFill(root, vec);
    int s = 0, e = vec.size() - 1;
    while(s < e){
        int sum = vec[s] + vec[e];
        if(sum < target)
            s++;
        else if(sum > target)
            e--;
        else{
            cout << vec[s] << " " << vec[e] << endl;
            s++;
            e--;
        }
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
    // targetSumPair(root, root, 100);
    targetSumPair2(root, 100);
    return 0;
}