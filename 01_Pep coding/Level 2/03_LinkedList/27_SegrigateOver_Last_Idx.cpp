/*
Segregate the linked list such that the all elements smaller than the last index value should be before it and all elements larger than last index value should come after it
Input Format
    1->5->2->9->5->14->11->1->10->10->1->3->null
Output Format
    1->1->1->2-> 3 ->5->9->5->14->11->10->10->null
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

Node *getTail(Node *head){
    if (head == nullptr) return nullptr;

    Node *tail = head;
    while (tail->next){
        tail = tail->next;
    }

    return tail;
}

Node* segLastIdx(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *tail = getTail(head);
    Node *smaller = new Node(-1);
    Node *prevS = smaller;

    Node *larger = new Node(-1);
    Node *prevL = larger;
    Node *curr = head;

    while(curr){
        if(curr->data <= tail->data){
            prevS->next = curr;
            prevS = prevS->next;
        }
        else{
            prevL->next = curr;
            prevL = prevL->next;
        }
        curr = curr->next;
    }
    prevS->next = tail;
    tail->next = larger->next;
    prevL->next = nullptr;
    return smaller->next;
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

    Node *ans = segLastIdx(dummy->next);
    LLTraversal(ans);
    return 0;
}  