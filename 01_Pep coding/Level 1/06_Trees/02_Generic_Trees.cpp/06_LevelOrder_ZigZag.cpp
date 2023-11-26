
#include <iostream>
#include <stack>
#include <queue>
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

void levelOrderZigZag(Node *root){
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    int levelCount = 0;
    while(!q.empty()){
        int size = q.size();
        if(levelCount % 2 == 0){
            for(int i = 0; i<size && levelCount % 2 == 0; i++){
                cout<<q.front()->data<<" ";
                for(Node *child : q.front()->children){
                    q.push(child);
                }
                q.pop();
            }
        }
        if(levelCount % 2 != 0){
            for(int i = 0; i<size; i++){
                s.push(q.front());
                for(Node *child : q.front()->children){
                    q.push(child);
                }
                q.pop();
            }
            while(!s.empty()){
                cout<<s.top()->data<<" ";
                s.pop();
            }
        }
        cout<<endl;
        levelCount++;
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
             
    o/p --> 10  
            40 30 20 
            50 60 70 80 90 100 
            120 110
*/
int main(){
    vector<int> vec = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(vec);
    levelOrderZigZag(root);
    return 0;
}   