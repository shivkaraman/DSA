#include <iostream>
using namespace std;

class Node{
    public:
        int val = 0;
        Node *next = nullptr;

        Node(int val){
            this->val = val;
        }
};

Node *reverse(Node *head){
    Node *curr = head, *prev = nullptr, *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    int n;
    cin >> n;

    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0){
        int val;
        cin >> val;
        prev->next = new Node(val);
        prev = prev->next;
    }

    Node *head = reverse(dummy->next);
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}