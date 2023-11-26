// 1. You are given a  BinaryTree.
// 2. You are given an element.
// 3. 3.1. find -> return true or false depending on if the data is found in binary tree.
//    3.2. nodeToRoot -> returns the path from node (correspoding to data) to root in form of an arraylist 
//         (root being the last element)
// 4. Input iand Output is managed for you.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public :
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* createTree(vector<int> pre){
    stack<pair<Node*, int>> s;
    Node *root = new Node(pre[0]);
    s.push({root, 1});
    int i = 1;
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){
            s.top().second++;
            if(pre[i] != 0){   
                temp.first->left = new Node(pre[i]);
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){
            s.top().second++;
            if(pre[i] != 0){  
                temp.first->right = new Node(pre[i]);
                s.push({temp.first->right, 1});
            }
            i++;
        }
        else{
            s.pop();
        }
    }
    return root;
}
 
static vector<int> path;
bool findPath(Node *root, int target){
    if(root == NULL)
        return false;
    if(root->data == target){
        path.push_back(root->data);
        return true;
    }
    bool checkLeft = findPath(root->left, target);  //Faith->Gives path from node to root->left(if target is found)
    if(checkLeft){
        path.push_back(root->data);
        return true;
    }
    bool checkRight = findPath(root->right, target); //Faith->Gives path from node to root->right(if target is found)
    if(checkRight){
        path.push_back(root->data);
        return true;
    }
    return false;
}
/*
                50  
               /  \
            25     75
            / \    / \
          12  37 62  87
              /   \  
            30    70
*/  
int main(){
    vector<int> pre = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(pre);
    int target;
    cin>>target;
    findPath(root, target);
    for(int i=0; i<path.size(); i++)    
        cout<<path[i]<<" ";
    return 0;
}