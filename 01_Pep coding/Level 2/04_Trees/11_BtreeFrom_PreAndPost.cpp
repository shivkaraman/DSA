/*
To construct a tree from pre and post order traversal it is necessary that that tree MYUST BE COMPLETE BTREE
https://www.youtube.com/watch?v=BroXN7Xrq4c&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=13

/*
preorder[startIdx] -> Root
postorder[x] == preorder[y]
All elements on the left  of idx in postorder -> Left subtree of root
All elements on the right of idx in postorder -> Right subtree of root
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
//E - Build a Btree using pre and post order
//F - left and right child already know how to build tree using pre and post order
//E-F - Pass left childs pre and post order to left child and right childs pre and post order to right child and curr node to left and right child
TreeNode *buildTree(vector<int> &preorder, int psi, int pei, vector<int> &postorder, int PTsi, int PTei){
    if(PTsi > PTei) return nullptr;

    TreeNode *node = new TreeNode(preorder[psi]);

    if(PTsi == PTei) return node;

    int idx = PTsi;
    while(postorder[idx] != preorder[psi+1]){
        idx++;
    }
    int countL = idx-PTsi+1;

    node->left = buildTree(preorder, psi+1, psi+countL, postorder, PTsi, idx);
    node->right = buildTree(preorder, psi+countL+1, pei, postorder, idx+1, PTei-1);

    return node;
}


TreeNode *buildTree( vector<int> &preorder, vector<int> &postorder){
    int n = postorder.size();
    return buildTree(preorder, 0, n-1, postorder, 0 , n-1); 
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

    vector<int> post(n, 0);
    for (int i = 0; i < n; i++){
        cin >> post[i];
    }

    TreeNode *root = buildTree(pre, post);
    display(root);
}

int main(){
    solve();
    return 0;
}