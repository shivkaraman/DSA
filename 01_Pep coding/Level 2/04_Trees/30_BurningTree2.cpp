/*
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

also find out the nodes which was burnt for each second
*/
#include <iostream>
#include <vector>
#include <map>
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

void height(TreeNode *node, int time, TreeNode *blocker, vector<vector<int>> &ans){
    if(node == nullptr || node == blocker) return;

    if(time >= ans.size()) 
        ans.push_back(vector<int> {node->val});
    else 
        ans[time].push_back(node->val);

    height(node->left, time+1, blocker, ans);
    height(node->right, time+1, blocker, ans);
}


int burnTree(TreeNode *node, int target, int &time, vector <vector<int>> &ans){
    if(node == nullptr) return -1;

    if(node->val == target){
        //Calculates time required to burn subtree below target node
        height(node, 0, nullptr, ans);
        return 1;
    }

    int leftTime = burnTree(node->left, target, time, ans);
    if(leftTime != -1){
        height(node, leftTime, node->left, ans);
        return leftTime+1;
    }
    int rightTime = burnTree(node->right, target, time, ans);
    if(rightTime != -1){
        height(node, rightTime, node->right, ans);
        return rightTime+1;
    }
    return -1;
}

vector <vector<int>> burningTree(TreeNode* root, int fireNode){
    // if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;

    int time = 0;
    vector <vector<int>> ans;
    burnTree(root, fireNode, time, ans);
    return ans;
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
    vector <vector<int>> ans = burningTree(root, fireNode);
    for(vector<int> &vec : ans){
        for(int &i : vec)
            cout << i << " ";
        cout << endl;
    }
}

int main(){
    solve();
    return 0;
}