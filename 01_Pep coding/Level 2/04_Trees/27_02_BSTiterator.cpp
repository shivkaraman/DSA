#include <iostream>
#include <vector>
#include <stack>
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

//Using Morris inorder traversal
class BSTIterator {
private:
    TreeNode *curr = nullptr;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int nextElement(){
        int val = -1;
        while(curr){
            TreeNode *ln = curr->left; // Left node
            //Left tree doesnot exist
            if(ln == nullptr){
                val = curr->val;
                curr = curr->right;
                break;
            }
            else{
                //Get rightmost element
                while(ln->right && ln->right != curr){
                    ln = ln->right;
                }
                //Create thread
                if(ln->right == nullptr){
                    ln->right = curr;
                    curr = curr->left;
                }
                //Left sub tree of curr node already traversed
                else{ // (ln->right == curr) -> This will be the case here
                    val = curr->val;
                    curr = curr->right;
                    //Removing thread
                    ln->right = nullptr;
                    break;
                }
            }
	    }
        return val;
    }
    int next() {
        return nextElement();
    }
    
    bool hasNext() {
        return curr != nullptr;
    }
};

//Input section
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

TreeNode* buildTree(vector<int>& inOrder, int si, int ei){
    if (si > ei)
        return nullptr;

    int mid = (si + ei) / 2;
    TreeNode* node = new TreeNode(inOrder[mid]);

    node->left = buildTree(inOrder, si, mid - 1);
    node->right = buildTree(inOrder, mid + 1, ei);

    return node;
}

TreeNode* constructFromInOrder(vector<int>& in){
    int n = in.size();
    return buildTree(in, 0, n - 1);
}

void solve(){
    int n;
    cin >> n;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++){
        cin >> in[i];
    }

    TreeNode* root = constructFromInOrder(in);
    BSTIterator itr(root);
    while (itr.hasNext()){
        cout << (itr.next()) << endl;
    }
}

int main(){
    solve();
    return 0;
}