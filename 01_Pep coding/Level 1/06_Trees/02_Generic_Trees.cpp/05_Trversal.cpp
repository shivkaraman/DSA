
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

//RECURSIVE
// void preOrder(Node *root){
//     cout<<root->data<<" ";
//     for(Node *child : root->children){
//         preOrder(child);
//     }
// }

// void postOrder(Node *root){
//     for(Node *child : root->children){
//         postOrder(child);
//     }
//     cout<<root->data<<" ";
// }

//ITERATIVE
void preOrder(Node *root){
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node *temp = s.top();
        cout<<temp->data<<" ";
        s.pop();
        int size = temp->children.size();
        for(int i = size-1; i>=0; i--){
            s.push(temp->children[i]);
        }
    }
}

void postOrder(Node *root){
    vector<int> vec;
    stack<Node*> s;
    s.push(root);

    while(!s.empty()) {
        Node *temp = s.top();
        s.pop();
        vec.push_back(temp->data);
        for(Node* node: temp->children)
            s.push(node);
    }
    for(int i = vec.size()-1; i>= 0; i--)
        cout<<vec[i]<<" ";
 }

void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            cout<<q.front()->data<<" ";
            for(Node *child : q.front()->children){
                q.push(child);
            }
            q.pop();
        }
        cout<<endl;
    }
}

//-1    -> Pre order, state++
// size -> post Order, pop
// 0< && <  children.size() --> state++, push that child
void prePost(Node *root){
    //pair <node, child index>
    stack<pair<Node*, int>> s;
    s.push({root, -1});
    string pre = "", post = "";
    while(!s.empty()){
        pair<Node*, int> temp = s.top();
        if(temp.second == -1){
            pre += to_string(temp.first->data) + " ";
            s.top().second++;
        }
        else if(temp.second == s.top().first->children.size()){
            post += to_string(temp.first->data) + " ";
            s.pop();
        }
        else{
            pair<Node*, int> cp = {temp.first->children[temp.second], -1};
            s.top().second++;
            s.push(cp);
        }
    }
    cout<<"Pre : "<<pre<<endl;
    cout<<"Post : "<<post<<endl;
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
    // cout<<"Pre Order : "; preOrder(root); cout<<endl<<endl;
    // cout<<"Post Order : "; postOrder(root); cout<<endl<<endl;
    // cout<<"Level Order : "<<endl; levelOrder(root);
    prePost(root);
    return 0;
} 
 
