//Given two sorted LL, merge the two linked list in sorted order
/*
   Here we follow the same approach as followed in brurteforce approach but instead of creating a new linked list, we modify the two 
   existing linked list ie change linke in the same linked list
*/

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

void LLTraversal(Node *head){
    Node *current = head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}


Node* MergeLL(Node *head1, Node *head2){  //T=O(n1+n2) S=O(1)
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    if(head1->data > head2->data){ //making LL1 as smaller one
        Node *temp = head1;
        head1 = head2;
        head2 = temp;
    }
    Node *res = head1;
    while(head1 && head2){
        Node *prev = NULL;
        while(head1 && head1->data <= head2->data){ //Breaks when element of ll1 > ll2
            prev = head1;
            head1 = head1->next;
        }
        prev->next = head2;

        //Swap head1 and head2
        Node *tmp = head1;
        head1 = head2;
        head2 = tmp;
    }
    return res;
}

int main(){ 
    Node *head1 = new Node;
    Node *head2 = new Node;
    head1 = LLInput();
    head2 = LLInput();

    cout<<"Linked List 1 : ";
    LLTraversal(head1);

    cout<<"Linked List 2 : ";
    LLTraversal(head2);

    Node *Merged = MergeLL(head1, head2);
    cout<<"Merged Linked List : ";
    LLTraversal(Merged);
    return 0;
}