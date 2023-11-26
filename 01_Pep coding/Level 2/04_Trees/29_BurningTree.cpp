/*
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
*/
#include <iostream>
#include <vector>
#include <queue>
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

int height(TreeNode *node, TreeNode *blocker){
    if(node == nullptr || node == blocker) return -1;

    int lh = height(node->left, blocker);
    int rh = height(node->right, blocker);
    return max(lh, rh)+1;
}

// Node to root path approach
int burnTree(TreeNode *node, int target, int &time){
    if(node == nullptr) return -1;

    if(node->val == target){
        //Calculates time required to burn subtree below target node
        time = height(node, nullptr);
        return 1;
    }

    //Here Left time and right time are NOT TIME REQ TO BURN LEFT AND RIGHT TREE
    //leftTime OR rightTime -> dist from curr to target node(ie timr required for fire to spread from tar->curr node)
    int leftTime = burnTree(node->left, target, time);
    if(leftTime != -1){
        int x = height(node, node->left);
        time = max(time, x+leftTime);
        return leftTime+1;
    }
    int rightTime = burnTree(node->right, target, time);
    if(rightTime != -1){
        int x = height(node, node->right);
        time = max(time, x+rightTime);
        return rightTime+1;
    }
    return -1;
}

int burningTree(TreeNode* root, int fireNode){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;

    int time = 0;
    burnTree(root, fireNode, time);
    return time;
}

// input_section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX){
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
        IDX[0]++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode* root = createTree(arr, IDX);

    int fireNode;
    cin >> fireNode;
    int ans = burningTree(root, fireNode);
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}