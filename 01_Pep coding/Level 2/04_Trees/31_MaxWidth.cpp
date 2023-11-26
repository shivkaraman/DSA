// https://leetcode.com/problems/maximum-width-of-binary-tree/
// https://www.youtube.com/watch?v=R9qiY7OK9JQ&list=PL-Jc9J83PIiHgjQ9wfJ8w-rXU368xNX4L&index=46

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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

//We use the concept of array representation of tree 
// Parent = i
// left child = 2*i+1
// right child = 2*i+2
int widthOfBinaryTree(TreeNode* root){
    queue < pair<TreeNode*, int> > q;
    q.push({root, 0});

    int mx = 0;
    while(!q.empty()){
        int size = q.size();
        int l = q.front().second;
        int r = q.front().second;
        while(size-- > 0){
            TreeNode *node = q.front().first;
            int idx = q.front().second;
            q.pop();

            r = idx;
            if(node->left) q.push({node->left, 2*idx + 1});
            if(node->right) q.push({node->right, 2*idx + 2});
        }
        mx = max(mx, r-l+1);
    }
    return mx;
}

int WidthOfBinaryTree(TreeNode* root){
    queue < pair<TreeNode*, int> > q;
    q.push({root, 0});

    int mx = 0;
    while(!q.empty()){
        int size = q.size();
        int l = q.front().second;
        int r = q.front().second;
        while(size-- > 0){
            TreeNode *node = q.front().first;
            int v = q.front().second;
            q.pop();

            r = v;
            if(node->left) q.push({node->left, v-1});
            if(node->right) q.push({node->right, v+1});
        }
        mx = max(mx, r-l);
    }
    return mx;
}

// input_Section_====================================================================

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

int idx = 0;
TreeNode* deserialize(vector<string>& arr){
    if (idx >= arr.size() || arr[idx].compare("null") == 0){
        idx++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(stoi(arr[idx++]));
    node->left = deserialize(arr);
    node->right = deserialize(arr);

    return node;
}

TreeNode* deserialize(string s){
    stringstream ss(s);
    string word;
    vector<string> arr;
    while (ss >> word){
        arr.push_back(word);
    }
    return deserialize(arr);
}

void solve(){
    string s;
    cin >> s;
    TreeNode* root = deserialize(s);

    cout << widthOfBinaryTree(root) << endl;
}

int main(){
    solve();
    return 0;
}