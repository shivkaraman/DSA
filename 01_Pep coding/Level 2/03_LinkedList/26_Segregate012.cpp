
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

Node* seg012(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *dummy0 = new Node(-1);
    Node *prev0 = dummy0;
    
    Node *dummy1 = new Node(-1);
    Node *prev1 = dummy1;

    Node *dummy2 = new Node(-1);
    Node *prev2 = dummy2;

    Node *curr = head;
    while(curr){
        if(curr->data == 0){
            prev0->next = curr;
            prev0 = prev0->next;
        }
        else if(curr->data == 1){
            prev1->next = curr;
            prev1 = prev1->next;
        }
        else{
            prev2->next = curr;
            prev2 = prev2->next;
        }
        curr = curr->next;
    }
    prev1->next = dummy2->next; //It is imortant to write this statement first -> REASON: DRYRUN FOR LL WITH ONLY 2'S
    prev0->next = dummy1->next;
    prev2->next = nullptr;
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

    Node *ans = seg012(dummy->next);
    LLTraversal(ans);
    return 0;
}  