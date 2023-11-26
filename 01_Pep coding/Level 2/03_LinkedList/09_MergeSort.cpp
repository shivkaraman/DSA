// T(N) = 2T(N/2) + 2N  = O(N logN)

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

Node* MergeLL(Node *head1, Node *head2){  //T=O(n1+n2) S=O(1)
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    Node *c1 = head1;
    Node *c2 = head2;
    Node *dummy = new Node(-1);
    Node *prev = dummy;

    while(c1 && c2){
        if(c1->data  < c2->data){
            prev->next = c1;
            c1 = c1->next;
        }
        else{
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }
    prev->next = c1 != nullptr ? c1 : c2;
    return dummy->next;
}

Node *middle(Node *head){
    if (head == nullptr || head->next == nullptr)
        return head ;

    Node *slow = head ;
    Node *fast = head ;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow;
}

Node* MergeSort(Node *head){
    if(head == nullptr)
        return nullptr;
    if(head->next == nullptr)
        return head;
    
    //Dividing linked list into two parts
    Node *mid = middle(head);
    Node *nHead = mid->next;
    mid->next = nullptr;

    //Merge left sorted and right sorted LL
    Node *left = MergeSort(head);
    Node *right = MergeSort(nHead);
    return MergeLL(left, right);
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

    Node *head = MergeSort(dummy->next);
    LLTraversal(head);
    return 0;
}  