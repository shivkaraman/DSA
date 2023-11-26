/*
    Given a singly linkedlist : l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln 
    reorder it : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> .....

    Input
        1->2->3->4->5->6->7->null
    Output
        1->7->2->6->3->5->4->null

    Steps
    1. Find mid
    2. break it into two LL
    3. fold
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

void fold(Node *head){    
    if(head == NULL || head->next == NULL)
        return;

    //Find the middle of the linked list
    Node *slow = head;
    Node *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse second half AND BREAK THE LINKED LIST INTO TWO SEPARATE PARTS
    Node *rhead = reverse(slow->next);
    slow->next = nullptr; 

    // Fold the linked list
    Node *node1 = head;
    Node *node2 = rhead;
    Node *n1Nxt , *n2Nxt = node2->next;
    while(node2 != nullptr){
        n1Nxt = node1->next;
        n2Nxt = node2->next;

        node1->next = node2;
        node2->next = n1Nxt;

        node1 = n1Nxt;
        node2 = n2Nxt;
    }
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

    fold(dummy->next);
    LLTraversal(dummy->next);
    return 0;
}  
