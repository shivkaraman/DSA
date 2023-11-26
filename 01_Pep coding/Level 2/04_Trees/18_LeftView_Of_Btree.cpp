#include <iostream>
#include <vector>
#include <queue>
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

vector<int> leftView(TreeNode *root){
    vector <int> ans;
    queue <TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        //Print first node of each level
        ans.push_back(q.front()->val);
        for(int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
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

       vector<int> ans = leftView(root);
    for (int i : ans)
        cout << i << endl;
}

int main(){
    solve();
    return 0;
}