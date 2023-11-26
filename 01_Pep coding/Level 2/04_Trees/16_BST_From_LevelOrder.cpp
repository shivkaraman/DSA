#include <iostream>
#include <queue>
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

class MyPair{
public: 
    TreeNode *node;
    int l, h;
    MyPair(TreeNode *node, int l, int h){
        this->node = node;
        this->l = l;
        this->h = h;
    }
};

TreeNode* buildBst(vector <int> &levelOrder){
    queue <MyPair> q;
    TreeNode *root;
    q.push(MyPair(nullptr, INT_MIN, INT_MAX));
    int idx = 0;

    while(!q.empty()){
        MyPair p = q.front();
        q.pop();
        int element = levelOrder[idx];
        
        if (element < p.l || element > p.h) continue;
    
        TreeNode *node = new TreeNode(element);
        idx++;

        if(p.node == nullptr) root = node;
        else{
            TreeNode *parent = p.node;
            if(element < parent->val) parent->left = node;
            else parent->right = node;
        }

        q.push(MyPair(node, p.l, element)); //Left range
        q.push(MyPair(node, element, p.h)); //Right right range

    }
    return root;
}

TreeNode *bstFromLevelOrder(vector<int> &levelOrder){
    return buildBst(levelOrder);
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
    vector<int> lvl(n, 0);
    for (int i = 0; i < n; i++){
        cin >> lvl[i];
    }

    TreeNode *root = bstFromLevelOrder(lvl);
    display(root);
}

int main(){
    solve();
    return 0;
}