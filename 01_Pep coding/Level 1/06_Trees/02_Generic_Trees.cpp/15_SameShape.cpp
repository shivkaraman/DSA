
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

bool areSameShape(Node *root1, Node *root2){
    if(root1->children.size() != root2->children.size()){
        return false;
    }
    for(int i = 0; i < root1->children.size(); i++){
        bool check = areSameShape(root1->children[i], root2->children[i]);
        if(!check){
            return false;
        }
    }
    return true;
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
    vector<int> vec1 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    vector<int> vec2 = {1, 2, 5, -1, 6, -1, -1, 3, 7, -1, 8, 11, -1, 12, -1, -1, 9, -1, -1, 4, 10, -1, -1, -1};
    // vector<int> vec2 = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    Node *root1= createTree(vec1);
    Node *root2 = createTree(vec2);
    cout<<areSameShape(root1, root2)<<endl;
    return 0;
}