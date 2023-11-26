//Giben two  binary trees, check if they are mirror of each other

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node{
    public : 
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

Node* createTree(vector<int> vec){    
    Node *root = new Node(vec[0]);

    pair<Node*, int> p = {root, 1};
    stack<pair<Node*, int>> s;
    s.push(p);

    for(int i=1; s.size()>0;){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){   //New node to left
            s.top().second++;
            if(vec[i] != 0/*NULL*/){
                temp.first->left = new Node(vec[i]);
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){ //New node to right
            s.top().second++;
            if(vec[i] != 0/*NULL*/){
                temp.first->right = new Node(vec[i]);
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
bool checkMirror(Node *root1, Node *root2){
    if(!root1 && !root2)
        return true;
    else if(!root1 || !root2)
        return false;
    bool lm = checkMirror(root1->left, root2->right);
    bool rm = checkMirror(root1->right, root2->left);
    return (root1->data == root2->data) && lm && rm;
}
/*
                50                      50
               /   \                   /  \
            25      75              75     25
            / \     / \            /\      / \
          12  37   62  87       87  62   37  12
              /\   / \             /\    /\
            30 51 100  70        70 100 51 30
*/ 
int main(){
    vector<int> vec1 = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, 51, NULL, NULL, 75, 62, 100, NULL, NULL, 70, NULL, NULL, 87, NULL, NULL};
    vector<int> vec2 = {50, 75, 87, 0, 0, 62, 70, 0, 0, 100, 0, 0, 25, 37, 51, 0, 0, 30, 0, 0, 12, 0, 0};//Mirror
    // vector<int> vec2 = {50, 75, 87, 0, 0, 62, 70, 0, 0, 100, 0, 0, 25, 37, 51, 0, 0, 30, 0, 0, 0};   //Not Mirror
    Node *root1 = createTree(vec1);
    Node *root2 = createTree(vec2);
    cout<<checkMirror(root1, root2)<<endl;
    return 0;
}