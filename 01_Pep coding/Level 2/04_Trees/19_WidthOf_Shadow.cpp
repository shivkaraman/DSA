// https://www.youtube.com/watch?v=rRBD5mS-N80&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=24

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

int mn = INT_MAX; //minimum vertical
int mx = INT_MIN; //maximum vertical
void width(TreeNode *node, int v){
    if(node == nullptr) return;

    mn = min(mn, v);
    mx = max(mx, v);
    width(node->left, v-1);
    width(node->right, v+1);
}
//Get max vertival and min vertical and calculate width
int widthOfBinaryTree(TreeNode* root) {
    width(root, 0);
    return mx-mn+1;
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

    cout << widthOfBinaryTree(root) << endl;
}

int main(){
    solve();
    return 0;
}