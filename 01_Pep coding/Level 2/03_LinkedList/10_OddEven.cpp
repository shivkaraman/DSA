/*
Given a singly linklist, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

Input
    1->7->2->6->3->5->4->null
Output
    2->6->4->1->7->3->5->null
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

Node* OddEven(Node *head){
    Node *current = head;
    Node *oddH = NULL, *evenH = NULL;
    Node *oddT = NULL, *evenT = NULL;
    while(current){
        if(current->data % 2 == 0){
            if(evenH == NULL){
                evenH = evenT = current;
            }
            else{
                evenT->next = current;
                evenT = current;
            }
        }
        else{
            if(oddH == NULL){
                oddH = oddT = current;
            }
            else{
                oddT->next = current;
                oddT = current;
            }   
        }
        current = current->next;
    }
    Node *nHead = evenH != nullptr ? evenH : oddH;
    if(evenH)
        evenT->next = oddH;
    if(oddH)
        oddT->next = nullptr;
    return nHead;
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

    Node *head = OddEven(dummy->next);
    LLTraversal(head);
    return 0;
}  