//using remove first add first method
//Steps are same like prev approach, but we easily get access to head and tail of each group making it easy to link groups

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

static Node *th = NULL; //temporaty head
static Node *tt = NULL; //temporaty tail
void addFirst(Node *node){
    if(th == nullptr){
        th = node;
        tt = node;
    }
    else{
        node->next = th;
        th = node;
    }
}

int length(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

Node* reverseKnodes(Node *head, int K){
    if(K==0 || K==1)
        return head;
    
    int len = length(head);
    Node *curr = head;
    Node *oh = nullptr, *ot = nullptr; //Original head and Original tail
    while(len >= K){
        int tempk = K;
        //Reverse K nodes
        while(tempk-- > 0){
            Node *next = curr->next;
            curr->next = nullptr;
            addFirst(curr);
            curr = next;
        }
        //Linking groups
        if(oh == nullptr){
            oh = th;
            ot = tt;
        }
        else{
            ot->next = th;
            ot = tt;
        }
        th = nullptr;
        tt = nullptr;
        len -= K;
    }
    ot->next = curr;
    return oh;
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