/*
https://leetcode.com/problems/binary-tree-cameras/

1. You are given a partially written function to solve.
2. You are required to complete the body of MinCamerasInBT_ function. The function is expected to return integer value representing minimum number of camera(s) required for the coverage of complete tree.
3.A camera is placed on any node will ensure coverage of parent-node as well as it's child-node(s), if any.
4. Input and Output is managed for you.

Sample Input
    15
    1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
Sample Output
    3
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

/*
We need to stat from the leaf nodes => traverse the tree in post order
-1 -> No camera but monitored
 0 -> Camera needed
 1 -> Having camera

Two cases arrise
	1. Child has camera => Already covered
	2. Child has no camera 
		2.1 But is covered => Curr node requests parent to buy camera
		2.2 Not covered => Child node needs camera =>  Curr node should buy camera

*/
static int camera = 0;
int CalcMinCameras(TreeNode* root) {
	if (root == nullptr) return -1;
    //If leaf node -> Camera neded for parent
    // else if (root->left == nullptr && root->right == nullptr) return 0; ---> THis gets automatically fullfiled
    
    int leftCheck = CalcMinCameras(root->left);
    int rightCheck = CalcMinCameras(root->right);

    //If any of the two child needs camera, we need to buy a camera for current node
    if (leftCheck == 0 || rightCheck == 0){
        camera++;
        return 1;
    }
    //If any of the two children are having the camera, then the current node is already Monitored
    else if (leftCheck == 1 || rightCheck == 1){
        return -1;
    }
    //If child has no camera but it is monitored -> Means currrent node needs camera so we request the parent
    else {
        return 0;
    }

} 

int minCameras(TreeNode *root){
    int check = CalcMinCameras(root);
    if(check == 0) camera++;
    return camera;
}

// input_section=================================================

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

	minCameras(root);
    cout << camera << endl;
}

int main(){
	solve();
	return 0;
}