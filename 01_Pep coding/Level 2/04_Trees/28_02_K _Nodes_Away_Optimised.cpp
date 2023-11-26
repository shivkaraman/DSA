// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
/*
In the previous example, We first get node -> root path from the function and then iterate over the path and call kDown function for (k-i)

We can optimize thids by calling kDown inside node-> root path function itself hence avoiding space for node-> root path vector and avoiding traversing the same node in the tree again (node by node->root and again by kdown)
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

vector<TreeNode*> ans;
void printKlevelsDown(TreeNode *node, int k, TreeNode *blocker){
    if(node == nullptr || k < 0 || node == blocker) return;
    if(k == 0){
        ans.push_back(node);
        return;
    }
    printKlevelsDown(node->left, k-1, blocker);
    printKlevelsDown(node->right, k-1, blocker);
}

int nodeToRootPath(TreeNode *node, int target,int k){
    if(node == nullptr) return -1;
    
    if(node->val == target){
        printKlevelsDown(node, k, nullptr);
        return 1;
    }
    
    int ld = nodeToRootPath(node->left, target, k); //left distance
    if(ld != -1){
        printKlevelsDown(node, k-ld, node->left);
        return ld+1;
    }
    int rd = nodeToRootPath(node->right, target, k);
    if(rd != -1){
        printKlevelsDown(node, k-rd, node->right);
        return rd+1;
    }
    return -1;
}

vector<TreeNode*> distanceK(TreeNode* root, int target, int k) {
    nodeToRootPath(root, target, k);
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
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode* root = createTree(arr, IDX);

    int target, k;
    cin >> target >> k;
    vector<TreeNode*> ans = distanceK(root, target, k);
    if (ans.size() == 0)
        cout << endl;
    for (TreeNode* node : ans){
        cout << node->val << " ";
    }
}

int main(){


    solve();
    return 0;
}