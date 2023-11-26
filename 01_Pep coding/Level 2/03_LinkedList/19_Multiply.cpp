// https://youtu.be/I5uKH3BWsLc?t=2423

#include<iostream>
#include<vector>
using namespace std;	 

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

Node* multiplyWithDigit(Node *head, int digit){
    if(head == NULL){
        return NULL;
    }
    Node *dummy = new Node(-1);
    Node *prev = dummy, *node = head;
    int carry = 0;
    while (node || carry){
        int mult = carry;
        if(node){
            mult += node->data * digit;
            node = node->next;
        }
        carry = mult/10;
        int dig = mult % 10;

        prev->next = new Node(dig);
        prev = prev->next;
    }
    return dummy->next;
}

void addLists(Node *head, Node *ans){
    Node *c1 = head;
    Node *c2 = ans;

    int carry = 0;
    while(c1 || carry){
        int sum = carry + (c1 != NULL ? c1->data : 0) + (c2->next != NULL ? c2->next->data : 0);

        int digit = sum % 10;
        carry = sum / 10;
         
        if(c2->next != NULL)
            c2->next->data = digit;
        else 
            c2->next = new Node(digit);

        if(c1) c1 = c1->next;
        c2 = c2->next;
    }
}

Node* multLinkedList(Node* l1, Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    Node *l2_itr = l2;
    Node *dummy = new Node(-1);
    Node *ans = dummy;
    while(l2_itr){
        Node *pdt = multiplyWithDigit(l1, l2_itr->data);
        l2_itr = l2_itr->next;

        addLists(pdt, ans);
        ans = ans->next;
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

    Node *head3 = multLinkedList(head1, head2);
    display(head3);
}