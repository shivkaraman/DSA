/*
Sample Input
    12
    1 1 1 4 5 6 6 7 8 9 9 9
Sample Output
    4 5 7 8 
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
    
    Node *dummy = new Node(-1) ;
    Node *itr = dummy ;
    itr->next = head ; // potential unique element .
    Node *curr = head->next ;
    while(curr){
        bool didLoopRun = false ;
        while(curr && itr->next->data == curr->data){
            didLoopRun = true ;
            curr = curr->next ;
        }

        if(didLoopRun) itr->next = curr ;
        else itr = itr->next ;

        if(curr) curr = curr->next ;
    }
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