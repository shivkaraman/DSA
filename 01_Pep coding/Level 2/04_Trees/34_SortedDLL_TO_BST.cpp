//Using Morris Innorder
//IN THIS QUESTION WHILE REMOVING A THREAD, REMOVE THREAD BEFORE CREATING THE LINK WLSE IT WILL CREATE PROBLEMS IN DLL

#include <iostream>
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

TreeNode *getMid(TreeNode *nodeS, TreeNode *nodeE){
    TreeNode *slow = nodeS;
    TreeNode *fast = nodeS;
    while(fast && fast != nodeE && fast->right){
        slow = slow->right;
        fast = fast->right->right;
    }
    return slow;
}

TreeNode* DLLtoBST(TreeNode *head, TreeNode *tail){
    if(head == tail){
        head->left = head->right = nullptr;
        return head;
    }

    TreeNode *mid = getMid(head, tail);
    mid->left = DLLtoBST(head, mid->left);
    mid->right = DLLtoBST(mid->right, tail);

    return mid;
}

void levelOrder(TreeNode *root){
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size-- > 0){
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
}

void solve(){
    int n;
    cin >> n;
    
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *prev = dummy;
    TreeNode *tail;
    for(int i =  0; i < n; i++){
        int x;
        cin >> x;

        TreeNode *curr = new TreeNode(x);
        curr->left = prev;
        prev->right = curr;
        prev = curr;

        tail = curr;
    }
    TreeNode *head = dummy->right;
    TreeNode *root = DLLtoBST(head, tail);
    levelOrder(root);
}

int main(){
    solve();
    return 0;
}