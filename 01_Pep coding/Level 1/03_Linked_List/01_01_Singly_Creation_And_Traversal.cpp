
#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *next;
};

void linkedListTraversal(Node *ptr){    //O(n) 
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next; 
    }
    cout<<endl;
}
int main(){
    //Allocate memory for linked list in HEAP
    Node *head   = new Node;
    Node *second = new Node;
    Node *third  = new Node;
    Node *fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
    linkedListTraversal(head);
    return 0;
}