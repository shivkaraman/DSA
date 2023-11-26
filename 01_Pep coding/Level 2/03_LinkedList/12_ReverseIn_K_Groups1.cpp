
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

Node* reverseKnodes(Node *head, int K){
    if(K==0 || K==1)
        return head;
    
    int len = 0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        len++;
    }
    
    Node *curr = head, *prev = NULL, *next; 
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *prevTail = dummy;
    while(len >= K){
        Node *first = curr; //First node of group 
        for(int i = 0; i  < K; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        len -= K;
        prevTail->next = prev;
        prevTail = first;
    }
    prevTail->next = curr;
    return dummy->next;
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

    int k;
    cin >> k;

    Node *head = reverseKnodes(dummy->next, k);
    LLTraversal(head);
    return 0;
}  