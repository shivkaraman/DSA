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

bool isValidBst(TreeNode* root) {
	if (!root) return true;

    TreeNode *prev = nullptr;
    TreeNode *curr = root;
    while(curr){
        TreeNode *left = curr->left;

        //NO left tree
        if(left == nullptr){
            if (prev && prev->val >= curr->val) return false;
            prev = curr;
            curr = curr->right;
        }
        else{
            while(left->right && left->right != curr){
                left = left->right;
            }
            if(left->right == nullptr){
                left->right = curr;
                curr = curr->left;
            }
            //Left sub tree finished
            else{
                if (prev && prev->val >= curr->val) return false;
                prev = curr;
                left->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return true;
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

	cout << (boolalpha) << isValidBst(root);
}

int main(){
	solve();
	return 0;
}