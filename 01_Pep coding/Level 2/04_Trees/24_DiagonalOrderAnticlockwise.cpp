#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

// https://www.youtube.com/watch?v=BZ49ZTWUbmg&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=30
vector<vector<int>> DiagonalTraversal(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);

    vector <vector<int>> ans;
    while(!q.empty()){
        int size = q.size();
        vector<int> diagonal;
        while(size-- > 0){
            TreeNode *node = q.front();
            q.pop();

            while(node){
                diagonal.push_back(node->val);
                if (node->right) q.push(node->right);
                node = node->left;
            }
        }
        ans.push_back(diagonal);
    }
    return ans;
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX){
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
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
    TreeNode *root = createTree(arr, IDX);

    vector<vector<int>> ans = DiagonalTraversal(root);
    int idx = 0;
    for (vector<int> &i : ans){
        cout << idx++ << " -> ";
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}