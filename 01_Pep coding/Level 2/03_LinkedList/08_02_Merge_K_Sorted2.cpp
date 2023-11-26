//using Priority Queue

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public : 
        int data;
        Node *next = nullptr;
        Node(int data){
          this->data = data;
        }
};

class myComparator{
    public : 
        bool operator()(Node* n1, Node *n2){
            return (n1->data > n2->data);
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

Node* mergeKSLL(vector<Node*> lists){
    if(lists.size() == 0)
        return nullptr;

    priority_queue< Node*, vector<Node*> , myComparator > pq;
    //Push head of each Linked List into PQ (if not null)
    for(Node *n : lists){
        if(n){
            pq.push(n);
        }
    }
    //Sort
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while(!pq.empty()){
        Node *node = pq.top();
        pq.pop();

        prev->next = node;
        prev = prev->next;

        if(node->next) pq.push(node->next);
    }
    prev->next = nullptr;
    return dummy->next;
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