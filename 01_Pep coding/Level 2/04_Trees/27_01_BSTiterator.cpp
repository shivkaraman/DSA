#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val){
        this->val = val;
    }
};

// https://www.youtube.com/watch?v=irozX_OvmKI&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=38
class BSTIterator { //This is an itrator which returns the next element of inoder traversal of BST when asked
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        addAllLeft(root);
    }
    
    void addAllLeft(TreeNode* root){
        while(root != nullptr){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        addAllLeft(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

//Input section
void display(TreeNode* node){
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

TreeNode* buildTree(vector<int>& inOrder, int si, int ei){
    if (si > ei)
        return nullptr;

    int mid = (si + ei) / 2;
    TreeNode* node = new TreeNode(inOrder[mid]);

    node->left = buildTree(inOrder, si, mid - 1);
    node->right = buildTree(inOrder, mid + 1, ei);

    return node;
}

TreeNode* constructFromInOrder(vector<int>& in){
    int n = in.size();
    return buildTree(in, 0, n - 1);
}

void solve(){
    int n;
    cin >> n;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++){
        cin >> in[i];
    }

    TreeNode* root = constructFromInOrder(in);
    BSTIterator itr(root);
    while (itr.hasNext()){
        cout << (itr.next()) << endl;
    }
}

int main(){
    solve();
    return 0;
}