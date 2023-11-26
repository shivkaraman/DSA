//Given a lined list, rearrrange all the nodes such that all the even elements occur before all the odd numbers

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

Node* LLInput(){
    Node *head = NULL;
    Node *node = head;
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

Node* OddEven(Node *head){
    Node *current = head;
    Node *oddList = NULL, *evenList = NULL;
    Node *oddListEnd = NULL, *evenListEnd = NULL;
    while(current){
        if(current->data % 2 == 0){
            if(evenList == NULL){
                evenList = evenListEnd = current;
            }
            else{
                evenListEnd->next = current;
                evenListEnd = current;
            }
        }
        else{
            if(oddList == NULL){
                oddList = oddListEnd = current;
            }
            else{
                oddListEnd->next = current;
                oddListEnd = oddListEnd->next;
            }   
        }
        current = current->next;
    }
    Node *nHead = evenList != NULL ? evenList : oddList;
    if(evenList)
        evenListEnd->next = oddList;
    if(oddList)
        oddListEnd->next = NULL;
    return nHead;
}


int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Original Linked List : ";
    LLTraversal(&head);

    head = OddEven(head);   
    cout<<"New Linked list : ";
    LLTraversal(&head);
    return 0;
}