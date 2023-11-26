/*
The first node in each vertical will only be visible when the tree is viewed from top
So we simply do vertical traversal and create an array list  containing first node of each vertical
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
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

vector<int> topView(TreeNode* root) {
    int w = widthOfBinaryTree(root);
    vector<int> vec(w, 0);
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int count = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int v = p.second;
        
        if(vec[v-mn] == 0){
            vec[v-mn] = node->val;
            count++;
        }
        if(count == w) break;
        
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

    vector<int> ans = topView(root);
    for(int &x : ans) cout << x << " ";
}

int main()
{
    solve();
    return 0;
}