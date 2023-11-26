/*

Given a singly linkedlist : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> ..... 
reorder it :  l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln

Input
    1->7->2->6->3->5->4->null
Output
    1->2->3->4->5->6->7->null

Steps
    1. Divide the  linked list into 2 parts
    2. reverse the second part
    2. append the reversed part
*/
#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next = nullptr;
        Node(int data){
          this->data = data;
        }
};

void LLTraversal(Node *head){
    Node *current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout << endl;
}

Node* reverse(Node *head){
    Node *current = head;
    Node *prev = nullptr;
    Node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void unFold(Node *head){    
    if(head == NULL || head->next == NULL)
        return;

    Node *tail = head;
    Node *nHead = head->next;

    Node *node1 = head;
    Node *node2 = nHead;
    while(node2){
        Node *n1Nxt = node2->next;
        Node *n2Nxt = node2->next != nullptr ? node2->next->next : node2->next; //Edge case for even length
    
        node1->next = n1Nxt;
        node2->next = n2Nxt;

        node1 = n1Nxt;
        node2 = n2Nxt;
        
        if(node1) tail = node1;
    }
    tail->next = reverse(nHead);
}  

int main(){
    int n;
    cin >> n;

    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0){
        int data;
        cin >> data;
        prev->next = new Node(data);
        prev = prev->next;
    }

    unFold(dummy->next);
    LLTraversal(dummy->next);
    return 0;
}  

