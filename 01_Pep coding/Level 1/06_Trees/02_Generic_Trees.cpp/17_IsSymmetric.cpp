//Mirror image of a symmmertric thing is itself, heace check if the tree is mirror of itself we check the SYMMETRY of mirror

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

bool areMirrorShape(Node *root1, Node *root2){
    if(root1->children.size() != root2->children.size()){
        return false;
    }

    for(int i = 0, j = root2->children.size() - 1; i < root1->children.size() && j >= 0; i++, j--){
        bool check = areMirrorShape(root1->children[i], root2->children[j]);
        if(!check){
            return false;
        }
    }
    return true;
}
/*
              10                      10
           /   |  \                 /  |  \             
         20   30  40              20  30  40
        /\   / | \  \            /   / | \  \
      50 60 70 80 90 100       50   70 80 90 100
               /\
             110 120
*/
int main(){
    // vector<int> vec = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    vector<int> vec = {10, 20, 50, -1, -1, 30, 70, -1, 80, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root= createTree(vec);
    cout<<areMirrorShape(root, root)<<endl;
    return 0;
}