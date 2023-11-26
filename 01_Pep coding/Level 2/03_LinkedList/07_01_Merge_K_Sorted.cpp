/*
You are given an array of k linked-lists, each linked-list is sorted in increasing order.
Merge all the linkedlists into one sorted linkedlist and return it.

Input
    3 sorted linkedlist :
        {
            0->0->0->null,
            0->0->1->1->1->2->2->4->null,
            0->0->0->0->5->5->6->null
        }
    Output
        after merging them : 
        0->0->0->0->0->0->0->0->0->1->1->1->2->2->4->5->5->6->null

Bruteforce : 
    Merge ith list with (i+1)th list till we reach kth list -> O(N * K^2)
Efficient : 
    Mergesort : 
        T(K) = 2T(K/2) + NK
        T(K) = O(NK logK)
*/

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public : 
        int data;
        Node *next = nullptr;
        Node(int data){
          this->data = data;
        }
};

Node* createList(int n){
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

Node* mergeKSLL(vector<Node*> lists, int si, int ei){
    if(si > ei)
        return nullptr;
    if(si == ei)
        return lists[si];
    
    int mid = (si + ei) / 2;
    Node *l1 = mergeKSLL(lists, si, mid);
    Node *l2 = mergeKSLL(lists, mid+1, ei);
    return MergeLL(l1, l2);
}

Node* mergeKSLL(vector<Node*> lists){
    if(lists.size() == 0)
        return nullptr;
    return mergeKSLL(lists, 0, lists.size() - 1);
}

int main(){
    int k;
    cin >> k;

    vector<Node*> lists(k);
    for(int i = 0; i <  k; i++){
        int n;
        cin >> n;

        lists[i] = createList(n);
    }
   
    Node *ML = mergeKSLL(lists);
    LLTraversal(ML);
    return 0;
}  