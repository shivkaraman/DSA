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

TreeNode* buildBst(vector <int> &postorder, int l, int h){
    static int idx = postorder.size()-1;
    if(idx >= postorder.size() || postorder[idx] > h || postorder[idx] < l)
        return nullptr;

    TreeNode *node = new TreeNode(postorder[idx--]);
    node->right = buildBst(postorder, node->val, h);
    node->left = buildBst(postorder, l, node->val);

    return node;
}

TreeNode *bstFromPostorder(vector<int> &postorder){
    return buildBst(postorder, INT_MIN, INT_MAX);
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
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    TreeNode *root = bstFromPostorder(post);
    display(root);
}

int main(){
    solve();
    return 0;
}