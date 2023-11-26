/*.
Insertion at first
    1. Point the next pointer of the new node to current head
    2. Update head pointer to point to new node
Insertion at last
    1. Point the next pointer of current last element to new node
    2. Point the next pointer of new node to NULL
Insertion at index
    1. Triverse through the linked list till index-1
    2. Update the node at index-1 to point to newNOde
    3. Update next pointer of newNode to point to node at idx
Insertion after a node
    1. Pass the  node after which newnode is to be inserted
    2. Update the next pointer of new node to next node of passed node
    3. Update the next pointer of node to point to newNode
*/


#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *next;
};

void linkedListTraversal(Node *ptr){        //O(n) 
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next; 
    }
    cout<<endl;
}

Node* InsertAtFirst(Node *head, int data){  //O(1)
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void InsertAtEnd(Node *ptr, int data){      //O(n)
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    while(ptr->next!=NULL){ //Moving to the last node
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void InsertAtMiddle(Node *ptr, int idx, int data){ //O(n) 
    Node *newNode = new Node;
    int i=0;
    while(i<idx-1){
        ptr = ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->data = data;
}

void InsertAfterNode(Node *node, int data){ //O(1)
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
}

int main(){
    //Allocate memory for linked list in HEAP
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
    
    cout<<"Initial Linked List : ";
    linkedListTraversal(head);

    //Insertion at first
    head = InsertAtFirst(head,1);
    cout<<"After insertion at first : ";
    linkedListTraversal(head);

    //Insertion at end
    InsertAtEnd(head,50);
    cout<<"After insertion at end: ";
    linkedListTraversal(head);

    //Insertion at index
    InsertAtMiddle(head,1,85);
    cout<<"After insertion at index 1: ";
    linkedListTraversal(head);

    //Insertion after a node
    InsertAfterNode(third,105);
    cout<<"After insertion after node: ";
    linkedListTraversal(head);
    
    return 0;
}