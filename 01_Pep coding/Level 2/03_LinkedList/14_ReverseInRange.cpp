/*
1. Given a singly linklist, Reverse a linkedlist from starting position to end position.
2. Do it in one-pass. without using any extra space.
3. Indexing start from numeric 1.

Input
    8->8->14->1->10->12->null 
    3
    5
Output
    8->8->10->1->14->12->null
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
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout << endl;
}

static Node *th = NULL; //temporaty head
static Node *tt = NULL; //temporaty tail
void addFirst(Node *node){
    if(th == nullptr){
        th = node;
        tt = node;
    }
    else{
        node->next = th;
        th = node;
    }
}
/*
1. Traverse till we are one node before REV RANGE
        link  curr
          |    |
          v    v
     8 -> 8 -> 14 -> 1-> 10 -> 12 -> null 

2. Reverse nodes in range
        link   tt        th    curr
          |    |         |      |
          v    v         v      v
     8 -> 8 -> 10 -> 1-> 14 -> 12 -> null 

3. link->next = th 
   tt->next = curr
*/
Node *reverseInRange(Node *head, int si, int ei){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *curr = head;
    Node *link = nullptr;
    int revRange = ei-si+1;
    //Iterate till link points to si ie node before reverse range
    while(--si > 0){
        link = curr;
        curr = curr->next;
    }
    Node *prev = nullptr;
    //Reverse nodes in given range
    while(curr && --revRange >= 0){
        Node *next = curr->next;
        curr->next = nullptr;
        addFirst(curr);
        curr = next;
    }
    if(link){
        link->next = th;
    }
    tt->next = curr;
    return link != nullptr ? head : th;
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

    int si, ei;
    cin >> si >> ei;
    Node *head = reverseInRange(dummy->next, si, ei);    
    LLTraversal(head);
    return 0;
}  