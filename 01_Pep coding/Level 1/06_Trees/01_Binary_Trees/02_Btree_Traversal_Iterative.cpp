
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node{
    public : 
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

//Iterative Method
void preOrderTraversal(Node *root){
    stack<Node*> s;
    while(1){
        while(root){
            //Print root
            cout<<root->data<<" ";
            s.push(root);
            //Left sub-tree (If left subtree exists, add to stack)
            root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        s.pop();
        //Right sub-tree(Left subtree completed, Now move to right subtree)
        root = root->right;
    }
}

void inOrderTraversal(Node *root){
    stack<Node*> s;
    while(1){
        while(root){
            s.push(root);
            //Left sub-tree(Get left subtree and keep on adding to stack)
            root = root->left; 
        }
        if(s.empty())
            break;
        root = s.top();
        s.pop();
        //Print root
        cout<<root->data<<" ";
        //Right sub-tree
        root = root->right;
    }
}

// void postOrderTraversal1(Node *root){  //s : 2*O(N)
//     vector<int> vec;
//     stack<Node*> s;
//     s.push(root);
//     while(!s.empty()){
//         Node *temp = s.top();
//         s.pop();
//         vec.push_back(temp->data);
//         if(temp->left)
//             s.push(temp->left);
//         if(temp->right)
//             s.push(temp->right);
//     }
//     for(int i = vec.size()-1; i >= 0; i--)
//         cout<<vec[i]<<" ";
// }

void postOrderTraversal2(Node *root){  //s : O(N)
    stack<Node*> s;
    Node *prev = NULL;
    do{
        while(root){
            //Left sub-tree
            s.push(root);
            root = root->left;
        }
        while(root == NULL && !s.empty()){ 
            root = s.top();
            //If right tree doesnot exist OR we are traversing up -> Print node and pop stack
            if(root->right == NULL || root->right == prev){
                //root->right wud be equal to prev only if the right child is 
                //already visited that means we are traversing up the b-tree
                
                //Printing root                            
                cout<<root->data<<" ";                     
                prev = root;
                s.pop();
                root = NULL;
            }
            //If right sub tree exists, go to right sub tree
            //Right sub-tree
            else{
                root = root->right;
            }
        }
    }while(!s.empty());
}

void PreInPost(Node *root){
    // 1 => pre, state++, left
    // 2 => in , state++, right
    // 3 => post, pop
    string pre = "", in = "", post = "";
    stack < pair<Node*, int> > s;
    s.push({root, 1});
    while(!s.empty()){
        pair <Node*, int> temp = s.top();
        if(temp.second == 1){       
            pre += to_string(temp.first->data) + " ";
            s.top().second++;
            if(temp.first->left != NULL)
                s.push({temp.first->left, 1});
        }
        else if(temp.second == 2){  
            in += to_string(temp.first->data) + " ";
            s.top().second++;
            if(temp.first->right != NULL)
               s.push({temp.first->right, 1});
        }
        else{                       
            post += to_string(temp.first->data) + " ";
            s.pop();
        }
    }
    cout<<"Pre : "<<pre<<endl;
    cout<<"In : "<<in<<endl;
    cout<<"Post : "<<post<<endl;
}

// https://www.youtube.com/watch?v=U7rLw0jXI0E&list=PL-Jc9J83PIiHYxUk8dSu2_G7MR1PaGXN4&index=10
void levelOrderTraversal(Node *root){ 
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node *temp = q.front();
            q.pop();
            //print cvurrent child
            cout<<temp->data<<" ";
            //At level 'l' add nodes of 'l+1'th level to queue
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        cout<<endl;
    }
}

// void levelOrder(Node *root){
//     if(!root)
//         return;
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         int count = q.size();
//         for(int i=0; i<count; i++){
//             Node *temp = q.front();
//             q.pop();
//             //print cvurrent child
//             cout<<temp->data<<" ";
//             //At level 'l' add nodes of 'l+1'th level to queue
//             if(temp->left != NULL)
//                 q.push(temp->left);
//             if(temp->right != NULL)
//                 q.push(temp->right);
//         }
//         cout<<endl;
//     }
// }
/*
            4
           / \
          1   6
         / \
        5   2 
*/
int main(){
    Node *root = new Node(4);
    Node *p2 = new Node(1);
    Node *p3 = new Node(6);
    Node *p4 = new Node(5);
    Node *p5 = new Node(2);

    root->left  = p2;
    root->right  = p3;
    p2->left = p4;
    p2->right = p5;

    cout<<"Pre Order : ";    
    preOrderTraversal(root);   
    cout<<endl;

    cout<<"In Order : ";     
    inOrderTraversal(root);    
    cout<<endl;

    cout<<"Post Order : ";   
    postOrderTraversal2(root);  
    cout<<endl;
    
    cout<<"Level Order : ";   
    levelOrderTraversal(root);  
    cout<<endl;

    PreInPost(root);
    return 0;
}