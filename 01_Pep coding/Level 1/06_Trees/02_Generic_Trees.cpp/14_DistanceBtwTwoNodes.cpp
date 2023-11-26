
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

vector<int> NodeToRootPath(Node *root, int data){
    vector<int> path;
    if(root->data == data){
        path.push_back(root->data);
        return path;
    }
    for(Node *child : root->children){
        vector<int> ptc = NodeToRootPath(child, data);
        if(ptc.size()){
            ptc.push_back(root->data);
            return ptc;
        }
    }
    return path;
}

int distance(Node *root, int n1, int n2){
    vector<int> path1 = NodeToRootPath(root, n1 );
    vector<int> path2 = NodeToRootPath(root, n2);
    int i = path1.size() - 1;    
    int j = path2.size() - 1;  
    while(i >= 0 && j >= 0 && path1[i] == path2[j]){
        i--;
        j--;
    }
    i++, j++;
    return i + j;
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
    int n1 = 50, n2 = 50;
    cout<<distance(root, n1, n2)<<" edges";
    return 0;
}