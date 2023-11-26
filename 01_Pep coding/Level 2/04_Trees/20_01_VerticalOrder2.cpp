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

 //Using DFS
void traversal(TreeNode *node, int v, map<int, vector<int>> &mp){
    if (node == nullptr) return;

    //v -> vertical no(..-2 -1 0 1 2..) , y -> level
    mp[v].push_back(node->val); 
    traversal(node->left, v-1, mp);
    traversal(node->right, v+1, mp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<int>> mp;
    traversal(root, 0, mp);
    vector<vector<int>> ans;
    for(auto p: mp){
        vector<int> col;
        col.insert(col.end(), p.second.begin(), p.second.end());
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

int main()
{
    solve();
    return 0;
}