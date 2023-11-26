
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public : 
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* createTree(vector<int> vec){
    stack<pair<Node*, int>> s;
    Node *root = new Node(vec[0]);
    s.push({root, 1});
    int i=1;
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == 1){
            s.top().second++;
            if(vec[i] != 0){
                temp.first->left = new Node(vec[i]);
                s.push({temp.first->left, 1});
            }
            i++;
        }
        else if(temp.second == 2){
            s.top().second++;
            if(vec[i] != 0){
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

int height(Node *root){
    if(root == NULL)
        return -1;
    int lh = height(root->left);        //Gives max height on left side
    int rh = height(root->right);       //Gives max height on right side
    int h = max(lh, rh) + 1;            
    return h;
}
/*
                50  
               /   \
            25      75
            / \     / \ 
          12  37  62  87
              /    \  
            30      70
                    /
                  100
*/  
int main(){
    vector<int> vec = {50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, 100, NULL, NULL, NULL, NULL, 87, NULL, NULL};
    Node *root = createTree(vec);
    cout<<height(root)<<endl;
    return 0;
}