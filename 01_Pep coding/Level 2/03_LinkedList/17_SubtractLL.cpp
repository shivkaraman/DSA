#include<iostream>
 #include<vector>
 using namespace std;	 

// Class declaration for a Node of the Linked List
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node* head) {
    for (Node* node = head; node != NULL; node = node->next) {
        cout << node->data << " ";
    }
}

Node *reverse(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *prev = NULL;
    Node *curr = head;
    while(curr){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* sublinkedList(Node* l1, Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    Node *dummy = new Node(0);
    Node *prev = dummy;
    int carry = 0;
    while(l1 || l2){
        int diff = carry;
        if(l1){
            diff += l1->data;
            l1 = l1->next;
        }
        if(l2){
            diff -= l2->data;
            l2 = l2->next;
        }
        if(diff < 0){
            diff += 10;
            carry = -1;
        }
        else
            carry = 0;
        prev->next = new Node(diff);
        prev = prev->next;
    }
    return reverse(dummy->next);
}

Node* createLL(int n){ 
    Node *dummy = new Node(0);
    Node *prev = dummy;

    while (n-- > 0){
        int data;
        cin >> data;
        prev->next = new Node(data);
        prev = prev->next;
    }
    return dummy->next;
}

int main(int argc, char** argv) {
    int n1;
    cin >> n1;
    Node *head1 = createLL(n1);

    int n2;
    cin >> n2;
    Node *head2 = createLL(n2);

    Node *head3 = sublinkedList(head1, head2);
    display(head3);
}