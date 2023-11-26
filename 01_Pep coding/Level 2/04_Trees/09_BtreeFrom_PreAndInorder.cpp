/*
preorder[idx] == inorder[idx] ==> That is a root element of some subtree
All elements on the left  of idx in inorder -> Left subtree of root
All elements on the right of idx in inorder -> Right subtree of root
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val){
        this->val = val;
    }
};

//E - Build a Btree using pre and inorder
//F - left and right child already know how to build tree using pre and inorder
//E-F - Pass left childs pre and inorder to left child and right childs pre and inorder to right child and curr node to left and right child
TreeNode *buildTree(vector<int> &preorder, int psi, int pei, vector<int> &inorder, int isi, int iei){
    if (isi > iei) return nullptr;
    
    TreeNode *node = new TreeNode(preorder[psi]);

    if(isi == iei) return node;
    int idx = isi;      
    while(inorder[idx] != preorder[psi]){
        idx++;
    }
    int countL = idx - isi; //count of left sub tree elements

    node->left = buildTree(preorder, psi+1, psi+countL, inorder, isi, idx-1);
    node->right = buildTree(preorder, psi+countL+1, pei, inorder, idx+1, iei);

    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
    int n = preorder.size();
    return buildTree(preorder, 0, n-1, inorder, 0 , n-1);

}

// input_Section_====================================================================

void display(TreeNode *node){
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve(){
    int n;
    cin >> n;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++){
        cin >> pre[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++){
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main(){
    solve();
    return 0;
}