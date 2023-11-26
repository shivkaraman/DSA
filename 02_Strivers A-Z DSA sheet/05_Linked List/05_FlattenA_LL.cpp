// https://takeuforward.org/data-structure/flattening-a-linked-list/\

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Node{
public:
    int data;
    Node *bottom;
    Node *next;
     Node(int data) {
        this->data = data;
        this->bottom = NULL;
        this->next = NULL;
    }
};

Node* mergeTwoLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
}

Node *flatten(Node *root){
    if (root == NULL || root->next == NULL) 
        return root; 

    // recur for list on right 
    root->next = flatten(root->next); 

    // now merge 
    root = mergeTwoLists(root, root->next); 

    // return the root 
    // it will be in turn merged with its left 
    return root; 
}
int main(){
    
    return 0;
}