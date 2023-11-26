/*
In inorder traversal, we print node if
    1. There is no left sub tree left ie node->left == NULL
    2. If left subtree is completely traversered

In threaded b-tree we move right(or we can also say we print a node) when    
    1. Left doesnot exist
    2. Left subtree is completely traversered

To find if the above condition is true we need some 'flag/condition' to tell if left subtree is traversed or it doesnot exist
    1. If node->left == NULL -> Left doesnot exist
    2. If node->left->right == current node -> Left is traversed -> COZ CHILD POINTS TO PARENT IFF THEREE IS A THREAD WHICH INDICATED THAT LEFT SUBTREE IS COMPLETELY TRAVERSED

//* In threaded b-tree we print when
//*     1. left child doesnot exist ie node->left == NULL
//*     2. When we destroy a thread (left tree traversed)
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

vector<int> morrisInTraversal(TreeNode* root) {
	if(root == nullptr){
		return vector<int>{};
	}
	TreeNode *curr = root;
	vector<int> ans;
	while(curr){
		TreeNode *ln = curr->left; // Left node
		//Left tree doesnot exist
		if(ln == nullptr){
			ans.push_back(curr->val);
			curr = curr->right;
		}
		else{
			TreeNode *rightmost = ln;	
			//Get rightmost element
			while(rightmost->right && rightmost->right != curr){
				rightmost = rightmost->right;
			}
			//Create thread
			if(rightmost->right == nullptr){
				rightmost->right = curr;
				curr = curr->left;
			}
			//Left sub tree of curr node already traversed
			else{ // (ln->right == curr) -> This will be the case here
				ans.push_back(curr->val);
				curr = curr->right;
				//Removing thread
				rightmost->right = nullptr;
			}
		}
	}
	return ans;
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

	vector<int> ans = morrisInTraversal(root);

	for (int i : ans){
		cout << i << " ";
	}
}

int main(){
	solve();
	return 0;
}