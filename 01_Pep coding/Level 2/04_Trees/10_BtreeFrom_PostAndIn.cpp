/*
postorder[x] == inorder[y] ==> That is a root element of some subtree
All elements on the left  of idx in inorder -> Left subtree of root
All elements on the right of idx in inorder -> Right subtree of root

All elements on left of idx in postorder -> Complete Sub tree of node
node x -> is root of the tree
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
//E - Build a Btree using post and inorder
//F - left and right child already know how to build tree using post and inorder
//E-F - Pass left childs post and inorder to left child and right childs post and inorder to right child and link curr node to left and right child
TreeNode *buildTree(vector<int> &postorder, int psi, int pei, vector<int> &inorder, int isi, int iei){
    if(isi > iei)
        return nullptr;

    TreeNode *node = new TreeNode(postorder[pei]);

    if(isi == iei) return node;
    
    int idx = isi;
    while(inorder[idx] != postorder[pei]){
        idx++;
    }
    int countL = idx - isi;

    node->left = buildTree(postorder, psi, psi+countL-1, inorder, isi, idx-1);
    node->right = buildTree(postorder, psi+countL, pei-1, inorder, idx+1, iei);

    return node;
}

TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder){
    int n = postorder.size();
    return buildTree(postorder, 0, n-1, inorder, 0 , n-1); 
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