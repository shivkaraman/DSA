#include <iostream>
#include <vector>
#include <queue>
#include <string>
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

void serialize(TreeNode *node, string &str){
    if(node == nullptr){
        str += "#,";
        return;
    }

    str += to_string(node->val) + ",";
    serialize(node->left, str);
    serialize(node->right, str);
}

// Encodes a tree to a single string.
string serialize(TreeNode *root){
    string str;
    serialize(root, str);
    return str;
}

int helper(string& data) {
    int pos = data.find(',');
    int val = stoi(data.substr(0,pos));
    data = data.substr(pos+1);
    return val;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string &data) {
    if (data[0]=='#') {
        if(data.size() > 1) 
            data = data.substr(2);
        return nullptr;
    } 
    TreeNode* node = new TreeNode(helper(data));
    node->left = deserialize(data);
    node->right = deserialize(data);
    return node;
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

    string s = serialize(root);
    display(deserialize(s));
}

int main(){
    solve();
    return 0;
}