// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

#include <iostream>
#include <vector>
#include <climits>
#include <cstdarg>
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

/*
This approach is same as calculatinn diameter of binary tree
Here we have 3 options 
  1. Left max or right max
  2. left node -> Root -> right node 
  3. Root -> Node of Left subtree OR Root -> Node of Right subtree 
  4. Only curr node (eg all values of tree are negative except root)
 
                         10
                    /  / /\ \  \ 
(10 20)option 3 <--/  / /  \ \  \ --> Option 3 (10 30)
                  /  v /    \  v \ 
                  20   |     30
                       v
                     Option 2 (20 10 30)        
*/
int getMaxSum(vector<int> vec){
    int mx = INT_MIN;

    for(int path: vec) mx = max(mx, path);
    return mx;
}

pair<int, int> ans(TreeNode *node){
    if(node == nullptr) return pair<int, int> {0, INT_MIN}; //REMEMBER THIS BASE CASE (VVIP)
    if(node->left == nullptr && node->right == nullptr) return pair<int, int> {node->val, node->val}; 

    //pair <Max node to root path sum, Max node to node path>
    pair<int, int> lp = ans(node->left);
    pair<int, int> rp = ans(node->right);
    pair<int, int> myPair;


    myPair.first = max(max(lp.first, rp.first) + node->val, node->val);
    myPair.second = getMaxSum(vector<int> {lp.second, rp.second, lp.first + rp.first + node->val, myPair.first});
    // myPair.second = max(max(max(max(lp.second, rp.second), lp.first + rp.first + node->val), myPair.first), node->val);

    return myPair;
}
int maxPathSum(TreeNode* root){   
    return ans(root).second;
}

// input_Section=================================================

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
    cout << maxPathSum(root) << endl;
}

int main(){
    solve();
    return 0;
}

