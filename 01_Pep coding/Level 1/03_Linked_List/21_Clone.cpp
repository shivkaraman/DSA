  // Clone a Linked List with each node having a next and random pointer
//https://www.youtube.com/watch?v=VNf6VynfpdM

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
        Node *random;
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

void LLTraversal(Node *head){
    Node *current = head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

Node* CloneLinkedList(Node *head){
    Node *node = head;
    Node *clone = NULL;
    //Step 1 -> Introducing new nodes of clone linked list btw original linked list
    while(node != NULL){
        clone = new Node;
        clone->data = node->data;
        clone->next = node->next; 
        clone->random = NULL;
        node->next = clone;
        node = node->next->next;
    }
    //Step 2 -> Updating random pointers of cloned linked list
    node = head;
    while(node != NULL){
        if(node->random != NULL)
            node->next->random = node->random->next;
        node = node->next->next;
    }
    //Step 3 -> Separating original linked list and cloned linked list
    Node *temp;
    node = head;
    clone = node->next;
    Node *cloneNode = clone;
    while(node != NULL){
        temp = cloneNode->next;
        if(temp != NULL)
            cloneNode->next = temp->next;
        else    
            cloneNode->next = NULL;
        node->next = temp;
        node = node->next;
        cloneNode = cloneNode->next;
    }
    return clone;
}

int main(){
    //Creating linked list
    Node* head = new Node;
    head->data = 1;

    head->next = new Node;
    head->next->data = 2;
    
    head->next->next = new Node;
    head->next->next->data = 3;

    head->next->next->next = new Node;
    head->next->next->next->data = 4;

    head->next->next->next->next = new Node;
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    //Linking random pointers
    head->random = head->next->next->next;
    head->next->random = head;
    head->next->next->random = head->next;
    head->next->next->next->random = NULL;
    head->next->next->next->next->random = head->next->next;
 
    cout<<"Linked List : ";
    LLTraversal(head);

    Node *clone = CloneLinkedList(head);
    cout << "Original Linked List: ";
    LLTraversal(head);
    cout<<"Cloned Linked List : ";
    LLTraversal(clone);
    return 0;
}