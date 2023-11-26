/*
1. Given a singly linklist, Segregate 01 Node of LinkedList and return pivot node of linkedlist.
2. After segregation zero nodes should come first and followed by ones node.
3. You are only allowed to swap data not swap nodes.
Input
    1->0->1->0->0->1->1->1->1->1->1->null

Output
    0->0->0->1->1->1->1->1->1->1->1->null
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

Node* seg01(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *dummy0 = new Node(-1);
    Node *dummy1 = new Node(-1);

    Node *prev0 = dummy0;
    Node *prev1 = dummy1;

    Node *curr = head;
    while(curr){
        if(curr->data == 0){
            prev0->next = curr;
            prev0 = prev0->next;
        }
        else{
            prev1->next = curr;
            prev1 = prev1->next;
        }
        curr = curr->next;
    }
    prev0->next = dummy1->next;
    prev1->next = nullptr;
    return dummy0->next;
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

    Node *ans = seg01(dummy->next);
    LLTraversal(ans);
    return 0;
}  