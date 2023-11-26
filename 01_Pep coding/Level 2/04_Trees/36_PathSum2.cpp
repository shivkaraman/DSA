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

vector<vector<int>> ans;
void pathSum(TreeNode *node, int targetSum, vector<int> psf){
    if(node == nullptr) return;

        if(node->left == nullptr && node->right == nullptr){
            psf.push_back(node->val);
            if(targetSum - node->val == 0){
                ans.push_back(psf);
            }
            return;        
    }

    psf.push_back(node->val);
    pathSum(node->left, targetSum - node->val, psf);
    pathSum(node->right, targetSum - node->val, psf);
    psf.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    pathSum(root, targetSum, vector<int>{});
    return ans;
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
    vector<vector<int>> ans = pathSum(root, tar);
    cout << "[ ";
    for(vector<int> &vec : ans){
        cout << "[";
        for(int &i : vec)
            cout << i << ", ";
        cout << "]";
    }
    cout << " ]";
}

int main(){
    solve();
    return 0;
}