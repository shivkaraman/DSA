//In this approack if two nodes of a level belong to same vertical, they are inserted into vector in sorted order(depending on node val)

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

//Using BFS or Level Order
vector<vector<int>> DiagonalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    // queue(node, vertical, level)
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty()) {
        int size = q.size();
        while(size-- > 0){
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[(y-x)/2][y].insert(node -> val);

            if (node->left) q.push({node -> left, {x - 1, y + 1}});
            if (node->right) q.push({node -> right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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