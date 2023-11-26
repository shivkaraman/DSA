// https://leetcode.com/problems/longest-univalue-path/

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

//Options are same as in NODE TO NODE PATH
 pair<int, int> ans(TreeNode *node){
    if(node == nullptr) return pair<int, int> {0, 0};
    
    //pair <longest path in left/right sub tree inc root->left/root->right  ,   max path len in left/right sub tree>
    pair<int, int> left = ans(node->left);
    pair<int, int> right = ans(node->right);
    pair<int, int> myPair = {0, 0};
    
    int l = 0, r  = 0;
    if(node->left && node->left->val == node->val) l = left.first+1;
    if(node->right && node->right->val == node->val) r = right.first+1;
    myPair.first = max(l, r);
    
    myPair.second = max(max(max(left.second, right.second), l+r), myPair.first) ;
    return myPair;
}

int longestUnivaluePath(TreeNode* root) {
    return ans(root).second;
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

    cout << longestUnivaluePath(root);
}

int main(){
  solve();
  return 0;
}

