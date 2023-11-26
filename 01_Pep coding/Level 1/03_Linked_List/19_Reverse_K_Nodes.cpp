
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

void LLTraversal(Node *head){
    Node *current = head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}


Node* reverseKnodes(Node *head, int K){
    if(K==0 || K==1)
        return head;
    
    int count = 0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    
    Node *curr = head, *prev = NULL, *next; 
    Node *dummy = new Node;
    dummy->next = head;
    Node *prevTail = dummy;
    while(count >= K){
        Node *first = curr;
        for(int i = 0; i  < K; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        count -= K;
        prevTail->next = prev;
        prevTail = first;
    }
    prevTail->next = curr;
    return dummy->next;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    int k;
    cin >> k;
    cout << "Linked List : ";
    LLTraversal(head);

    head = reverseKnodes(head, k);
    cout << endl << "KNodes Reversed : ";
    LLTraversal(head);
    return 0;
}  