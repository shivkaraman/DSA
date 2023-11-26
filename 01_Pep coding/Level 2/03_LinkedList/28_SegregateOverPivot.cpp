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

Node *getPivot(Node *head, int pivotIdx){
    if (head == nullptr) return nullptr;

    Node *pivot = head;
    while (pivot && pivotIdx--){
        pivot = pivot->next;
    }

    return pivot;
}

Node* segPivot(Node *head, int pivotIdx){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *pivot = getPivot(head, pivotIdx);

    Node *smaller = new Node(-1);
    Node *prevS = smaller;

    Node *larger = new Node(-1);
    Node *prevL = larger;

    Node *curr = head;
    int idx = 0;
    while(curr){
        if (idx == pivotIdx); //Do nothing
        else if(curr->data <= pivot->data){
            prevS->next = curr;
            prevS = prevS->next;
        }
        else{
            prevL->next = curr;
            prevL = prevL->next;
        }
        curr = curr->next;
        idx++;
    }
    prevS->next = pivot;
    pivot->next = larger->next;
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

    int pivotIdx;
    cin >> pivotIdx;
    Node *ans = segPivot(dummy->next, pivotIdx);
    LLTraversal(ans);
    return 0;
}  