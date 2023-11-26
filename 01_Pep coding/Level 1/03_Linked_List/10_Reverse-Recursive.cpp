//Reverse a singly linked list

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

void LLTraversal(Node **head){
    Node *current = *head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

//Faith --> Reverse all n-1 elements and return head of reversed ll, i will reverse the first todes
Node* Reverse(Node *head){  //O(n) --> T(n-1)+1 = O(n)      T=O(n)                                 10->20->30->40->50
    if(head == NULL || head->next == NULL){               //S=O(n) for recursive stack
        return head;
    }
    Node *newHead = Reverse(head->next);  //Reverses n-1 elements and returns its new head         10->20<-30<-40<-50 , newHead->50
    (head->next)->next = head;                                                             //      10<-20->30->40->50
    head->next = NULL;                                                                     //NULL<-10<-20->30->40->50
    return newHead;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    cout<<"Reversed Linked List : ";
    head = Reverse(head);
    LLTraversal(&head);
    return 0;
}