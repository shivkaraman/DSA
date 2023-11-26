#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

static int idx = 0;
TreeNode* buildBst(vector <int> &preorder, int l, int h){
    if(idx >= preorder.size() || preorder[idx] > h || preorder[idx] < l)
        return nullptr;

    TreeNode *node = new TreeNode(preorder[idx++]);
    node->left = buildBst(preorder, l, node->val);
    node->right = buildBst(preorder, node->val, h);

    return node;
}

TreeNode *bstFromPreorder(vector<int> &preorder){
    return buildBst(preorder, INT_MIN, INT_MAX);
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
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int main(){
    solve();
    return 0;
}