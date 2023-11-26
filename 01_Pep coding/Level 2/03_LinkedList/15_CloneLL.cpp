//Clone a Linked List with each node having a next and random pointer

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public : 
        int data;
        Node *next = nullptr;
        Node *random = nullptr;
        Node(int data){
          this->data = data;
        }
};

Node* CloneLinkedList(Node *head){
    Node *node = head;
    Node *clone = NULL;
    //Step 1 -> Introducing new nodes of clone linked list btw original linked list
    while(node != NULL){
        clone = new Node(node->data);
        clone->next = node->next; 
        clone->random = NULL;

        node->next = clone;
        node = node->next->next;
    }
    //Step 2 -> Updating random pointers of cloned linked list
    node = head;
    while(node != NULL){
        if(node->random != NULL)
            node->next->random = node->random->next;
        node = node->next->next;
    }
    //Step 3 -> Separating original linked list and cloned linked list
    Node *temp;
    node = head;
    clone = node->next;
    Node *cloneNode = clone;
    while(node != NULL){
        temp = cloneNode->next;
        if(temp != NULL)
            cloneNode->next = temp->next;
        else    
            cloneNode->next = NULL;
        node->next = temp;
        node = node->next;
        cloneNode = cloneNode->next;
    }
    return clone;
}

int main(){
    int n;
    cin >> n;

    vector<Node *> arr(n);
    Node *prev = nullptr;
    for (int i = 0; i < n; i++){
        arr[i] = new Node(0);
        if (prev != nullptr)
            prev->next = arr[i];
        prev = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int data, idx;
        cin >> data >> idx;

        arr[i]->data = data;
        if (idx != -1)
            arr[i]->random = arr[idx];
    }

    Node *head = CloneLinkedList(arr[0]);
    while (head != nullptr){
        cout << "(" + to_string(head->data) + ", " + (head->random != nullptr ? to_string(head->random->data) : to_string(-1)) + ") ";
        head = head->next;
    }

    return 0;
}  