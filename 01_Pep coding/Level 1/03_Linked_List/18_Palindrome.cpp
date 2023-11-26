/*
1. Find the middle of the linked list(in case of even no of elements, consider the first middle element)
2. Reverse the seconnd half of the linked list
3. Compare the first and second part of the linked list
4. Reconstruct the original linked list by revrsing the seconnd part again
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

Node* reverse(Node *head){
    Node *current = head;
    Node *prev = NULL;
    Node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool checkPalindrome(Node **head){    
    Node *node1 = *head;
    Node *node2;
    bool check = true;
    //Find the middle of the linked list
    Node *slow = *head;
    Node *fast = *head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //Reverse second half
    slow->next = reverse(slow->next);
    node2 = slow->next;
    //Compare first and second part
    while(node2){
        if(node1->data != node2->data){
            check = false;
            break;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    //Construct the original linked list by reversing the second half
    node2 = reverse(slow->next);
    slow->next = node2;
    return check;
}  

int main(){
     Node *head = new Node;
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    bool check = checkPalindrome(&head);
    if(check)
        cout<<"Palindrome"<<endl;
    else    
        cout<<"Not Palindrome"<<endl;
    return 0;
}