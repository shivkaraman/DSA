
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

static Node* prediscissor = NULL;
static Node* successor = NULL;
static int state = 0;
void getPredisscissorAndSuccessor(Node *root, int data){
    if(state == 0){    
        if(root->data == data)  //Element found -> Increase state to 1
            state++;
        else                    //Element not found -> Keep updating prediscissor 
            prediscissor = root;
    }
    else if(state == 1){        //Element is found and successor is to be found
        successor = root;
        state++;
    }       
    else                        //Prediscissor and successor found -> return
        return;
    for(Node *child : root->children){
        getPredisscissorAndSuccessor(child, data);
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
    getPredisscissorAndSuccessor(root, 30);
    if(prediscissor == NULL)
        cout<<"No prediscissor"<<endl;
    else
        cout<<"Prediscissor = "<<prediscissor->data<<endl;
        
    if(successor == NULL)
        cout<<"No successor"<<endl;
    else
        cout<<"Successor = "<<successor->data<<endl;
    return 0;
}