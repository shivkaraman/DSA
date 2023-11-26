//Given two sorted LL, merge the two linked list in sorted order
/*Bruteforce approach --> Create a new LL and keep comparing the nodes of first and second ll and update the new LL
    1. Copy head1 and head2 to h1 and h2
    2. Create a newLL head
    3. Repeat the following steps till h1 and h2 end
        if h1->data < h2->data
            add h1 to new LL
            update h1 to h1->next
        Follow similar steps if h2->data < h1->data
    4. Return newnLL head
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

void LLTraversal(Node **head){
    Node *current = *head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

// Bruteforce Approach 
// Node* MergeLL(Node *head1, Node *head2){  //T=O(n1+n2) S=O(n1+n2)
//     Node *newLL = NULL;
//     Node *prev = NULL;
//     while(head1 != NULL || head2 != NULL){
//         Node *newNode = new Node;
//         if(head1 == NULL){
//             newNode->data = head2->data;
//             head2 = head2->next;
//         }
//         else if(head2 == NULL){
//             newNode->data = head1->data;
//             head1 = head1->next;
//         }
//         else if(head1->data < head2->data){
//             newNode->data = head1->data;
            // head1 = head1->next;
//         }
//         else{
//             newNode->data = head2->data;
//             head2 = head2->next;
//         }
//         if(newLL == NULL)
//             newLL = newNode;
//         else    
//             prev->next = newNode;
//         newNode->next = NULL;
//         prev = newNode;
//     }
//     return newLL;
// }

Node* MergeLL(Node *head1, Node *head2){  //T=T(n-1)+1=O(n)   S=O(n1+n2)  where n=n1+n2
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;

    Node *newNode = new Node;

    if(head1->data < head2->data){
        newNode->data = head1->data;
        newNode->next = MergeLL(head1->next, head2);
    }
    else if(head2->data < head1->data){
        newNode->data = head2->data;
        newNode->next = MergeLL(head1, head2->next);
    }
    return newNode;
}

int main(){ 
    Node *head1 = new Node;
    Node *head2 = new Node;
    head1 = LLInput();
    head2 = LLInput();

    cout<<"Linked List 1 : ";
    LLTraversal(&head1);

    cout<<"Linked List 2 : ";
    LLTraversal(&head2);

    Node *Merged = MergeLL(head1, head2);
    cout<<"Merged Linked List : ";
    LLTraversal(&Merged);
    return 0;
}