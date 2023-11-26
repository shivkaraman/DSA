/*
https://leetcode.com/problems/house-robber-iii/

1. You are given a partially written function to solve.
2. The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.
3. Input and Output is managed for you.

Sample Input
    15
    1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
Sample Output
    4
*/
#include <iostream>
#include <vector>
#include <queue>
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

//Expectation -> find max value  that can be robbed
//Faith -> Children kknow to give max value if thay were <robbed, not robbed> 
//EF -> If we rob curr node, consider value of children which was not robbed
//   -> If we dont want to rob curr node, we consider max value of children robbed or not robbed
pair <int, int> calcMaxVal(TreeNode* root) {
    if(root == nullptr) return  pair <int, int> {0, 0};
    
    // < Robbed,  Not Robbbed>
    pair <int, int> left = calcMaxVal(root->left);
    pair <int, int> right = calcMaxVal(root->right);

    //Rob root => Left and right node must not be included
    int rob = left.second + right.second + root->val;
    
    //Root Not Robbed => WE have option to  left, not  left (same for right)
    int leftMax = max(left.second, left.first);     //Which gives max value? When we rob left ot not rob  left
    int rightMax = max(right.second, right.first);  //Which gives max value? When we rob right or not rob  right
    int Nrob = leftMax + rightMax;

    pair <int, int> curr = {rob, Nrob};
    return curr;
} 

int HouseRobber(TreeNode *root){
    pair <int, int> p = calcMaxVal(root);
    return max(p.first, p.second);
}

// input_section==================================================================================================================

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

    cout << HouseRobber(root);
}

int main(){
	solve();
	return 0;
}