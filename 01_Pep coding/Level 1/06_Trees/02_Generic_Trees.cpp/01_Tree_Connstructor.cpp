
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

//Expectation-> To display itself and its family 
//Faith -> children of root know to display its whole family
//E-F->display itsef(its children) and tell children to display their family
void display(Node *root){
    // if(root->children.size() == 0){      -->This would be the base case, but its not required coz when there are no children,  
    //     cout<<root->data<<"->."<<endl;       the two loops would not run and wud eventually return by printing a "."
    //     return;
    // }
    cout<<root->data<<"->";
    for(Node *child : root->children){
        cout<<child->data<<" ";
    }
    cout<<"."<<endl;
    //Faith
    for(Node *child : root->children){
        display(child);
    }
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
    vector<int> vec = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(vec);
    display(root);
    return 0;
}