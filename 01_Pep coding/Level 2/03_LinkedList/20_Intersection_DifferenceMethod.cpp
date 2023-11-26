/*
1. Given the heads of two singly linked-lists headA and headB
2. Return the node at which the two lists intersect. 
3. If the two linked lists have no intersection, return null.
*/
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

int lengthOfLL(Node *node){
    if (node == nullptr){
        return 0;
    }

    int len = 0;
    while (node != nullptr){
        node = node->next;
        len++;
    }

    return len;
}

Node *IntersectionNodeInTwoLL(Node *headA, Node *headB){
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    int l1 = lengthOfLL(headA);
    int l2 = lengthOfLL(headB);

    Node *biggerList = l1 > l2 ? headA : headB;
    Node *smallerList = l1 > l2 ? headB : headA;

    int diff = max(l1, l2) - min(l1, l2);
    while (diff-- > 0)
        biggerList = biggerList->next;

    while (biggerList != smallerList){
        biggerList = biggerList->next;
        smallerList = smallerList->next;
    }

    return biggerList;
}

Node *makeList(int n){
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0){
        int data;
        cin >> data;
        prev->next = new Node(data);
        prev = prev->next;
    }
    return dummy->next;
}

int main(){
    int n,idx;
    cin >> n;
    Node *head1 = makeList(n);
    cin >> idx;
    
    int m;
    cin >> m;
    Node *head2 = makeList(m);

    if (idx >= 0){
        Node *curr = head1;

        while (idx-- > 0)
            curr = curr->next;

        Node *prev = head2;
        while (prev->next != nullptr)
            prev = prev->next;

        prev->next = curr;
    }

    Node *ans = IntersectionNodeInTwoLL(head1, head2);
    cout << (ans != nullptr ? ans->data : -1) << endl;
    return 0;
}
