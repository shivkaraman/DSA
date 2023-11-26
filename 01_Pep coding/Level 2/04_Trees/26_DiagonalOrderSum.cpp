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

vector<int> DiagonalTraversal(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);

    vector <int> ans;
    while(!q.empty()){
        int size = q.size();
        int diagonal = 0;
        while(size-- > 0){
            TreeNode *node = q.front();
            q.pop();

            while(node){
                diagonal += node->val;
                if (node->left) q.push(node->left);
                node = node->right;
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

    vector<int> ans = DiagonalTraversal(root);
    int idx = 0;
    for (int &i : ans){
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}