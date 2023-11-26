
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

Node* MergeLL(Node *head1, Node *head2){  //T=O(n1+n2) S=O(1)
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    Node *c1 = head1;
    Node *c2 = head2;
    Node *dummy = new Node(-1);
    Node *prev = dummy;

    while(c1 && c2){
        if(c1->data  < c2->data){
            prev->next = c1;
            c1 = c1->next;
        }
        else{
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }
    prev->next = c1 != nullptr ? c1 : c2;
    return dummy->next;
}

int main(){
    int n1;
    cin >> n1;

    Node *dummy1 = new Node(-1);
    Node *prev = dummy1;
    while (n1-- > 0){
        int data;
        cin >> data;
        prev->next = new Node(data);
        prev = prev->next;
    }

    int n2;
    cin >> n2;

    Node *dummy2 = new Node(-1);
    prev = dummy2;
    while (n2-- > 0){
        int data;
        cin >> data;
        prev->next = new Node(data);
        prev = prev->next;
    }

    Node *head = MergeLL(dummy1->next, dummy2->next);
    LLTraversal(head);
    return 0;
}  