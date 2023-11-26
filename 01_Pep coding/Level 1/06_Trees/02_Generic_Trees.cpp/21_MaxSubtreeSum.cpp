//Find node wth maximum subtree sum

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node{
    public :
        int data;    
        vector<Node*> children;
        Node(int data){
            this->data = data;
        }
};

Node* createTree(vector<int> vec){
    stack<Node*> s;
    Node *root = new Node(vec[0]);
    s.push(root);
    int i = 1;
    while(!s.empty()){
        if(vec[i] == -1){
            s.pop();
        }
        else{
            Node *child = new Node(vec[i]);
            s.top()->children.push_back(child);
            s.push(child);
        }
        i++;
    }
    return root;
}

Node *node;
static int maxSum = INT_MIN;
int maxSubtreeSum(Node *root){  //Returns Subtree sum 
    int sum = 0;
    for(Node *child : root->children){
        int csum = maxSubtreeSum(child);
        sum += csum;
    }
    sum += root->data;
    if(sum > maxSum){
        node = root;
        maxSum = sum;
    }
    return sum;
}
/*
              10
           /   |  \
         20   30  40
        /\   / | \  \
      50 60 70 80 90 100
               /\
             110 120
*/
int main(){
    vector<int> vec = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    Node *root = createTree(vec);
    maxSubtreeSum(root);
    cout<<node->data<<endl;
    return 0;
}