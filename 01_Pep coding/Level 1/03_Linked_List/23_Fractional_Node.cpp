//Given a linekd list , find n/k th element
// 1. Take two pointers, P1 and P2. 
// 2. For every k jumps of P1, increment P2.
// 3. Continue till P1 != NULL.
// 4. Return P2

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

Node* LLInput(){
    Node *head = NULL;
    Node *prev = NULL;
    int choice, i = 1;
    do{
        Node *newNode = new Node;
        cin>>newNode->data;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else    
            prev->next = newNode;

        prev = newNode;
        cin>>choice;
    }while(choice != 0);
    return head;
}

Node* FractionalNode(Node *head, int k){
    // Corner cases 
    if (k <= 0 || head == NULL) 
        return NULL;    
  
    // Traverse the given list 
    int i; 
    Node *p1 = head;
    Node* p2 = NULL; 
    for (i = 0; p1 != NULL; p1 = p1->next) { 
        if (i % k == 0){   //Checking if P1 moves by distance of k
            if(p2 == NULL)
                p2 = head; 
            else    
                p2 = p2->next;
        }
        i++; 
    } 
    return p2; 
}
    
int main(){
    Node *head = new Node;
    head = LLInput();

    int k;
    cin>>k;
    Node *fractionalNode = FractionalNode(head, k);
    if(fractionalNode)
        cout<<"Fractional Node : "<<fractionalNode->data<<endl;
    else    
        cout<<"Fractional Node cannot be found"<<endl;
    return 0;
}