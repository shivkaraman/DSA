// https://leetcode.com/problems/recover-binary-search-tree/

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

/*
Two nodes can be swapped in 3 ways
1. Both in left subtree
2. Both in right subtree
3. Node from left and right subtree

In case 1 and 2, the tree will have only one faulty node (DRY RUN TO UNDERSTAND)

So we need to handle only one case ie case 3 (Coz it is given that there are 2 faulty nodes)
The faulty node can be found this way
    Left sub tree : (prev && prev->val >= curr->val) when this condition is true in left sub tree, the faulty node will be 'prev'
    Right sub tree : (prev && prev->val >= curr->val) when this condition is true in right sub tree, the faulty node will be 'curr'
*/
void recoverTree(TreeNode *root){
    if (!root) return;

    TreeNode *prev = nullptr;
    TreeNode *curr = root;
    TreeNode *node1 = nullptr;
    TreeNode *node2 = nullptr;
    while(curr){
        TreeNode *left = curr->left;
        //NO left tree
        if(left == nullptr){
            if(prev && prev->val >= curr->val){
                if(node1 == nullptr) 
                    node1 = prev;
                node2 = curr;
            }
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
                if(prev && prev->val >= curr->val){
                    if(node1 == nullptr) 
                        node1 = prev;
                    node2 = curr;
                }
                prev = curr;
                left->right = nullptr;
                curr = curr->right;
            }
        }
    }
    //Swapping the nodes
    if(node1){
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
}

// input_Section_====================================================================

void display(TreeNode *node){
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
    recoverTree(root);
    display(root);
}

int main(){
    solve();
    return 0;
}