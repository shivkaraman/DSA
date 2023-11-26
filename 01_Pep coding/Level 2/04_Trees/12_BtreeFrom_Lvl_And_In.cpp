
#include <iostream>
#include <vector>
#include <unordered_set>
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
//E - Build a Btree using inorder and level order
//F - left and right child already know how to build tree using inorder and level order
//E-F - Pass left childs inorder and level order to left child and right childs inorder and level order to right child and curr node to left and right child
TreeNode *buildTree(vector<int> &inorder, int isi, int iei, vector<int> &levelOrder){
    if(isi > iei) return nullptr;
    
    TreeNode *node = new TreeNode(levelOrder[0]);

    if(levelOrder.size() == 1) return node;

    int idx = isi;
    while(inorder[idx] != levelOrder[0]){
        idx++;
    }

    //Creating level order for left and right sub tree
    unordered_set<int> s;
    for(int i = isi; i < idx; i++){
        s.insert(inorder[i]);
    }
    vector <int> levelOrderL;
    vector <int> levelOrderR;
    for(int i = 0; i < levelOrder.size(); i++){
        int ele = levelOrder[i];
        if(!s.empty() && s.find(ele) != s.end()){
            levelOrderL.push_back(ele);
            s.erase(ele);
        }
        else
            levelOrderR.push_back(ele);
    }

    node->left = buildTree(inorder, isi, idx-1, levelOrderL);
    node->right = buildTree(inorder, idx+1, iei, levelOrderR);

    return node;
}

TreeNode *buildTree( vector<int> &inorder, vector<int> &levelOrder){
    int n = inorder.size();
    return buildTree(inorder, 0, n-1, levelOrder); 
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

    vector<int> lvl(n, 0);
    for (int i = 0; i < n; i++){
        cin >> lvl[i];
    }

    TreeNode *root = buildTree(in, lvl);
    display(root);
}

int main(){
    solve();
    return 0;
}