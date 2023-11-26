//Given two numbers in form of two linked lists, add the two numbers and make a new linked list of sum 

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

Node* reverse(Node *LL){
    Node *current = LL;
    Node *prev = NULL;
    Node *next;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* Add(Node **ll1, Node **ll2){
    Node *head1 = *ll1 = reverse(*ll1);
    Node *head2 = *ll2 = reverse(*ll2);
    Node *newLL = new Node;
    Node *temp = newLL;
    int carry = 0 ;
    while(head1 || head2 || carry){
        int sum = carry;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }
        carry = sum/10;
        sum = sum%10;

        Node *newNode = new Node;
        newNode->data = sum;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    *ll1 = reverse(*ll1);
    *ll2 = reverse(*ll2);
    return reverse(newLL->next);
}

int main(){
    Node *head1, *head2;
    head1 = LLInput();
    head2 = LLInput();
    
    Node *sum = Add(&head1, &head2);
    cout<<"Sum of "; LLTraversal(&head1); cout<<"and "; LLTraversal(&head2); cout<<"is "; LLTraversal(&sum);
    return 0;
}