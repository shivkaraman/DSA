
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

Node* RootNthNode(Node *head){
    if (head == NULL) 
        return NULL;    
 
    Node* rootNthNode = NULL; 
    for (int i=1, n=1; head != NULL; head = head->next) { 
        if(i == n*n){
            if(rootNthNode == NULL)
                rootNthNode = head;
            else    
                rootNthNode = rootNthNode->next;
            n++;
        }
        i++;
    } 
    return rootNthNode; 
}
    
int main(){
    Node *head = new Node;
    head = LLInput();
    
    Node *rootNthNode = RootNthNode(head);
    if(rootNthNode)
        cout<<"Root nth Node : "<<rootNthNode->data<<endl;
    else    
        cout<<"Root nth Node cannot be found"<<endl;
    return 0;
}