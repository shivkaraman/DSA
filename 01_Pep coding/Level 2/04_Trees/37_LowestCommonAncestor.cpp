#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class TreeNode{
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val){
        this->val = val;
    }
};

// https://www.youtube.com/watch?v=_-QHfMDde90
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == nullptr || root->val == p || root->val == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) 
        return root;
    else if (left != nullptr)
        return left;
    else 
        return right;
    
}

// input_Section_====================================================================

void display(TreeNode* node){
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

TreeNode* createTree(vector<int>& arr, vector<int>& IDX){
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
        IDX[0]++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
    TreeNode* root = createTree(arr, IDX);

    int p, q;
    cin >> p >> q;

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    if(ans) cout << ans->val;
    else cout << "null";
}

int main(){
  solve();
  return 0;
}

