// https://www.youtube.com/watch?v=VYczyMiMTqA&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=60
// https://leetcode.com/problems/all-possible-full-binary-trees/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

//func already knows to construct fullBT for left and right sub tree and return root of left/right subtree
vector<TreeNode*> allPossibleFBT(int n) {
    if(n == 1) return vector<TreeNode*> {new TreeNode(0)};

    vector<TreeNode*> ans;
    for(int i = 1; i < n; i+=2){ // -> This is the most inportant statement because the main property we are using in this questio is that a FULL BT can have either 0 or 2 children => node 0, 2, 4... ie with even idx can never become root
    
        vector<TreeNode*> left = allPossibleFBT(i);         //Returns root of left fullBT(left subtree) 
        vector<TreeNode*> right = allPossibleFBT(n-i-1);    //Returns root of right fullBT(right subtree)
        for(TreeNode *l : left){
            for(TreeNode *r : right){
                TreeNode *root = new TreeNode(0);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    //Returns root oof all full bt's
    vector<TreeNode *> ans = allPossibleFBT(n);
    
    return 0;
}