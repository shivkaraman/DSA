
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


static Node *th = NULL; //temporary head
static Node *tt = NULL; //temporary tail
void addFirst(Node *node){
    if(th == nullptr){
        th = tt = node;
    }
    else{
        node->next = th;
        th = node;
    }
}

Node* reverse(Node *head){
    Node *curr = head;
    while(curr){
        Node *next = curr->next;
        curr->next = nullptr;
        addFirst(curr);
        curr = next;
    }
    return th;
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

    Node *head = reverse(dummy->next);
    LLTraversal(head);
    return 0;   
}  