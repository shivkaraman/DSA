//In this approack if two nodes of a level belong to same vertical, they are inserted into vector in order in which it is visited(NOT SORTED)

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

int mn = INT_MAX;
int mx = INT_MIN;
void width(TreeNode *node, int v){
    if(node == nullptr) return;

    mn = min(mn, v);
    mx = max(mx, v);
    width(node->left, v-1);
    width(node->right, v+1);
}

int widthOfBinaryTree(TreeNode* root) {
    width(root, 0);
    return mx-mn+1;
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    int w = widthOfBinaryTree(root);
    vector <vector<int>> vec(w);
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int v = p.second;
        
        vec[v-mn].push_back(node->val);
        if (node->left) q.push({node -> left, v-1});
        if (node->right) q.push({node -> right, v+1});
    }
    return vec;
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

    vector<vector<int>> ans = verticalTraversal(root);
    int idx = 0;
    for (vector<int> &i : ans){
        cout << idx++ << " -> ";
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    solve();
    return 0;
}