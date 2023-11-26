//In order solution
#include <iostream>
#include <vector>
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
/*
WKT the inorder traversal of a bst is sorted in acscending order
Hence if we run inorder traersal and keep track of prev element in the traversal
if prev->val >= curr->val then the elemets are not in ascending order => NOT BST
*/
bool validate(TreeNode* node, TreeNode* prev) {
    if (node == NULL) 
        return true;

    if (!validate(node->left, prev))
         return false;
    if (prev != NULL && prev->val >= node->val) 
        return false;
    prev = node;
    return validate(node->right, prev);
}

 bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return validate(root, prev);
}

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
    cout << (boolalpha) << isValidBST(root);
}

int main(){
    solve();
    return 0;
}