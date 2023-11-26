#include <iostream>
#include <vector>
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

TreeNode* buildBst(vector<int> &inorder, int si, int ei){
    if(si > ei) return nullptr;

    int mid = (si + ei)/2;
    TreeNode *node = new TreeNode(inorder[mid]);
    node->left = buildBst(inorder, si, mid-1);
    node->right = buildBst(inorder, mid+1, ei);

    return node;

};

TreeNode *bstFromInorder(vector<int> &inorder){
    return buildBst(inorder, 0, inorder.size()-1);
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
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++){
        cin >> in[i];
    }

    TreeNode *root = bstFromInorder(in);
    display(root);
}

int main(){
    solve();
    return 0;
}