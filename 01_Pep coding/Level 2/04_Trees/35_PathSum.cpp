// https://leetcode.com/problems/path-sum/

#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

 bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;

    if(root->left == nullptr && root->right == nullptr){
        return (targetSum-root->val == 0);
    }
    
    return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
}

// input_Section=================================================

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
    int tar;
    cin >> tar;
    vector<int> IDX(1, 0);
    TreeNode* root = createTree(arr, IDX);
    cout << (boolalpha) << hasPathSum(root, tar) << endl;
}

int main(){
    solve();
    return 0;
}