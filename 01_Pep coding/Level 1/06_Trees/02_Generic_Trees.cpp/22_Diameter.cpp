
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

//https://www.youtube.com/watch?v=GIA2cZgOdwg&list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_&index=50
static int dia = 0;
int CalcDiaReturnHeight(Node *root){
    int dch = -1;                               //Deepest child height
    int sdch = -1;                              //Second deepest child height
    //Calculating height of Deepest node and second deepest node
    for(Node *child : root->children){
        int ch = CalcDiaReturnHeight(child);    //Child height
        if(ch > dch){
            sdch = dch;
            dch = ch;
        }
        else if(ch > sdch){
            sdch = ch;
        }
    }
    //Calculating diameter
    if(dch + sdch + 2 > dia){
        dia = dch + sdch + 2;
    }
    dch++;
    return dch;
}
/*
              10
           /   |  \
         20   30  40
        /\   / | \  \
      50 60 70 80 90 100
               /\
             110 120
             /
            130
*/
int main(){
    vector<int> vec = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, 130, -1, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(vec);
    CalcDiaReturnHeight(root);
    cout<<dia<<endl;
    return 0;
}