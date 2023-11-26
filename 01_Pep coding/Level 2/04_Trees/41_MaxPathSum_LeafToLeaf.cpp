//  return Integer value depending upon maximum leaf-to-leaf paths sum.

#include <iostream>
#include <vector>
#include <climits>
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

//This approach is same as calculatign diameter of binary tree
pair<int, int> ans(TreeNode *node){
    if(node == nullptr) return pair<int, int> {INT_MIN, INT_MIN};
    if(node->left == nullptr && node->right == nullptr) return pair<int, int> {node->val, INT_MIN}; 

    //pair <Max leaf to root path sum, Max left to leaf path in left or right sub tree>
    pair<int, int> lp = ans(node->left);
    pair<int, int> rp = ans(node->right);
    pair<int, int> myPair;

    myPair.first = max(lp.first, rp.first) + node->val;
    myPair.second = max(max(lp.second, rp.second), lp.first + rp.first + node->val);

    return myPair;
}
int maxPathSum(TreeNode* root){
    return ans(root).second;
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
    vector<int> IDX(1, 0);
    TreeNode* root = createTree(arr, IDX);
    cout << maxPathSum(root) << endl;
}

int main(){
    solve();
    return 0;
}