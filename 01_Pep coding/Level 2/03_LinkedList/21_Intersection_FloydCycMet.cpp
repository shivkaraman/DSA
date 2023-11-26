// https://www.youtube.com/watch?v=lAi11qfSsTM&list=PL-Jc9J83PIiGRqcfZxxgOKovgLVd3znnq&index=21
/*
1. Link tail of first linked list to head of second linked list
2. Run FIND STARTING POINT OF CYCLE IN LL code to get the intersection point 
3. If null is returned then no intersection else the cycle starting point is the intersection point is the intersection point

*/
#include <iostream>
using namespace std;

class Node{
public:
    int val = 0;
    Node *next = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node* tailOfLL(Node *node){
    if (node == nullptr)
        return nullptr;

    while (node->next != nullptr){
        node = node->next;
    }

    return node;
}

Node* floydCycleStartPt(Node *head){
    if(head == nullptr || head->next == nullptr)
        return nullptr;
    
    Node *slow = head;
    Node *fast= head;
    bool looped = false;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            looped = true;
            break;
        }
    }
    if(looped){
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return (looped ? slow : nullptr);
}

Node *IntersectionNodeInTwoLL(Node *headA, Node *headB){
    if (headA == nullptr || headB == nullptr) return nullptr;

    Node *tail = tailOfLL(headA);
    tail->next = headB; //Modyify 

    Node *intersect = floydCycleStartPt(headA);

    tail->next = nullptr; //Unmodify
    return intersect;
}

Node *makeList(int n){
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new Node(val);
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

    if (idx >= 0)
    {
        Node *curr = head1;

        while (idx-- > 0)
            curr = curr->next;

        Node *prev = head2;
        while (prev->next != nullptr)
            prev = prev->next;

        prev->next = curr;
    }

    Node *ans = IntersectionNodeInTwoLL(head1, head2);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}