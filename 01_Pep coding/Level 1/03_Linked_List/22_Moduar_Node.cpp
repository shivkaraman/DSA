/*
1.  Given a linked list, write a function find the last element from the BEGINNING whose n%k=0
    eg -> n=19 and k=3
      return 18th node 
2.  Given a linked list, write a function find the last element from the END whose n%k=0
    eg -> n=19 and k=3
      return 17th node 
*/

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

Node* ModularNodeBeginning(Node *head, int k){
    // Corner cases 
    if (k <= 0 || head == NULL) 
        return NULL;    
  
    // Traverse the given list 
    int i; 
    Node* modularNode = NULL; 
    for (i = 1; head != NULL; head = head->next) { 
        if (i % k == 0)  
            modularNode = head; 
        i++; 
    } 
    return modularNode; 
}

Node* ModularNodeEnd(Node *head, int k){
    if (k <= 0 || head == NULL) 
        return NULL;  
    int i=0;
    Node* modularNode = head;
    for(i = 1; i<k ; i++){
        if(head)
            head = head->next;
        else
            return NULL;
    }
    while(head->next){
        modularNode = modularNode->next;
        head = head->next;
    }
    return modularNode; 
}
    
int main(){
    Node *head = new Node;
    head = LLInput();

    int k;
    cin>>k;
    Node *modularNode = ModularNodeBeginning(head, k);
    if(modularNode)
        cout<<"Modular Node from beginning : "<<modularNode->data<<endl;
    else    
        cout<<"Modular node from beginning cannot be found"<<endl;

    modularNode = ModularNodeEnd(head, k);
    if(modularNode)
        cout<<"Modular Node from end : "<<modularNode->data<<endl;
    else    
        cout<<"Modular node from end cannot be found"<<endl;
    return 0;
}