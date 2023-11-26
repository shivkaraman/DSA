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

bool isCyclePresentInLL(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) return true;
    }
    return false;
}

Node *takeInput(){
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
    int idx;
    cin >> idx;
    if (idx >= 0){
        Node *curr = dummy->next;
        while (idx-- > 0){
            curr = curr->next;
        }
        prev->next = curr;
    }
    return dummy->next;
}

int main(){
    Node *head = takeInput();
    cout << (boolalpha) << isCyclePresentInLL(head) << endl;
    return 0;
}