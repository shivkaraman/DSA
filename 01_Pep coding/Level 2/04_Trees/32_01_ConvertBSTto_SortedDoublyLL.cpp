//Using DFS

#include <iostream>
#include <vector>
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

TreeNode *head = nullptr;
TreeNode *Prev = nullptr;
void bToDll(TreeNode* root){
    if(root == nullptr) return;

    bToDll(root->left);

    //Creating link of DLL
    if(head == nullptr) head = root;
    else{
        Prev->right = root; 
        root->left = Prev;
    }
    Prev = root;

    bToDll(root->right);
}

TreeNode* bToDLL(TreeNode *root){
    if(root == nullptr) return root;

    bToDll(root);
    //Creating curcular link
    Prev->right = head;
    head->left = Prev;

    return head;
}

// input_Section_====================================================================

void display(TreeNode* node){
    TreeNode* head = node;
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->right;
        if (node == head)
        break;
    }
}

TreeNode* constructFromInOrder(vector<int>& inOrder, int si, int ei){
    if (si > ei)
        return nullptr;
    int mid = (si + ei) / 2;
    TreeNode* root = new TreeNode(inOrder[mid]);

    root->left = constructFromInOrder(inOrder, si, mid - 1);
    root->right = constructFromInOrder(inOrder, mid + 1, ei);

    return root;
}

TreeNode* constructFromInOrder(vector<int>& inOrder){
    return constructFromInOrder(inOrder, 0, inOrder.size() - 1);
}

void solve(){
    int n;
    cin >> n;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++){
        cin >> in[i];
    }

    TreeNode* root = constructFromInOrder(in);
    TreeNode* head = bToDLL(root);
    display(head);
}

int main(){
    solve();
    return 0;
}