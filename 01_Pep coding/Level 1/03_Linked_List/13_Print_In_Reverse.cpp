//Traverse the linked list recursively and reach the tail and priint the content while returning

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

Node* LLInput(){
    Node *head = new Node;
    head = NULL;
    Node *prev = NULL;
    int choice;
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

void reversePrint(Node *head){ //T = T(n-1)+1 = O(n)  S=O(n)
    if(head == NULL)
        return;
    reversePrint(head->next);
    cout<<"<-"<<head->data;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Linked List in reverse order : NULL"; reversePrint(head);
    return 0;
}