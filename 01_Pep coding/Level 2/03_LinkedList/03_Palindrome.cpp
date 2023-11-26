#include <iostream>
using namespace std;

class Node{
    public:
        int data = 0;
        Node *next = nullptr;

        Node(int data){
            this->data = data;
        }
};

Node* reverse(Node *head){
    Node *current = head;
    Node *prev = NULL;
    Node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool checkPalindrome(Node *head){    

    //Find the middle of the linked list
    Node *slow = head;
    Node *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse second half
    Node *rhead= reverse(slow->next);
    slow->next = nullptr;

    //Compare first and second part
    Node *node1 = head;
    Node *node2 = rhead;
    bool check = true;

    while(node2){
        if(node1->data != node2->data){
            check = false;
            break;
        }
        node1 = node1->next;
        node2 = node2->next;
    }

    //Construct the original linked list by reversing the second half
    slow->next = reverse(rhead);
    return check;
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
    cout << (boolalpha) << checkPalindrome(dummy->next) << endl;
    return 0;
}