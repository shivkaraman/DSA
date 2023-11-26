//Post order solution
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

class bstPair{
public:
    bool isBst;
    int mx, mn;
};
// Is tree BST = left sub tree is bst  AND right sub tree is bst AND current node satisfies conditon of bst
//Current node condition -> if root->data >= LeftMax  then root->data is greater than the whole left subtree
//                          if root->data <= RightMin then root->data is smaller than the whole right subtree
bstPair isBST(TreeNode *root){
    if(root == nullptr){
        bstPair base;
        base.isBst = true;
        base.mx = INT_MIN;
        base.mn = INT_MAX;
        return base;
    }
    bstPair left = isBST(root->left);
    bstPair right = isBST(root->right);

    bstPair curr;
    curr.isBst = left.isBst && right.isBst && root->val > left.mx && root->val < right.mn;
    curr.mx = max(root->val, max(left.mx, right.mx));
    curr.mn = min(root->val, min(left.mn, right.mn));

    return curr;
}

bool isValidBST(TreeNode *root){
    bstPair check = isBST(root);
    return check.isBst;
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
    for (int i = 0; i < n; i++)
    {
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