/*
1. You are give a single sorted linkedlist of numbers. 
2. remove all duplicate nodes such that duplicate numbers appear once and Return the remaning linked list.

Sample Input
    12
    1 1 1 4 5 6 6 7 8 9 9 9
Sample Output
    1 4 5 6 7 8 9
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

Node* remDup(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *dummy = new Node(-1);
    Node *curr = head;
    Node *itr = dummy;
    while(curr){
        if(itr->data != curr->data){
            itr->next = curr;
            itr = itr->next;
        }
        curr = curr->next;
    }
    itr->next = nullptr;
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

    Node *ans = remDup(dummy->next);
    LLTraversal(ans);
    return 0;
}  