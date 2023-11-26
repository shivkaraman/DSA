/*
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

1. Choose any node in the binary tree and a direction (right or left).
2. If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
3. Change the direction from right to left or from left to right.
4. Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Sample Input 
    15 
    1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
Sample Output
    4
*/
#include <iostream>
#include <vector>
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

class Pair{
public:
    int left = -1;   //path length including root considering left direction
    int right = -1;  //path length including root considering right direction
    int mx = 0;     //Max path length from root
};

Pair calc(TreeNode *node){
    if(node == nullptr)
        return Pair();

    Pair pairL = calc(node->left);
    Pair pairR = calc(node->right);

    Pair ans;
    ans.left = pairL.right + 1; 
    ans.right = pairR.left + 1;
    ans.mx = max(max(ans.left, ans.right), max(pairL.mx, pairR.mx));

    return ans;
}

int longestZigZagPath(TreeNode *root){
    return calc(root).mx;
}



// input_Section_====================================================================

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

    cout << longestZigZagPath(root) << endl;
}

int main(){
    solve();
    return 0;
}