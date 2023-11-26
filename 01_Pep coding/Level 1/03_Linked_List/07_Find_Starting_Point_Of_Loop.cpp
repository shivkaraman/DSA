/*
Find if a linked list is NULL terminated or not. If ther is a cycle, find the starting point of the cycle
This is an extensionn of prev problem 
If the linked list is cycled, then initialise slowptr to head and mive both fastptr and slowptr by distance of 1
The point at which they meet is is the node at which loop starts

//* Let L1 = distance from head to starting point of cycle
//*     L2 = distance from starting point of cycle to intersection ppoint of slow ans fast ptr
//* 
//* Dist travelled by slow ptr = L1 + L2
//* Dist travelled by fast ptr = L1 + L2 + nC    where C -> Length of cycle
//* 
//*     2 * Speed of slow ptr = fast ptr
//* =>  2 (L1 + L2) = L1 + L2 + nC
//* =>  L1 + L2 = nC
//* => L1 = nC - L2 
//* 
//* Which basically means DIST FROM HEAD TO STARTING POINT = DIST FROM INTERSECTION POINT OF SLOW AND FAST TO STARTING PT OF CYCLE
*/
#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

Node* LoopedOrNot(Node **head){  //T=O(n) S=O(1)
    Node *slowptr = *head;
    Node *fastptr = *head;
    bool looped = false;
    while(fastptr && slowptr && fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr){
            looped = true;
            break;
        }
    }
    if(looped){
        slowptr = *head;
        while(slowptr != fastptr){
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        return slowptr;
    }
    return NULL;
}

int main(){
    //Allocate memory for linked list in HEAP
    Node *head   = new Node;
    Node *second = new Node;
    Node *third  = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

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
    fourth->next = fifth;
    
    //Looping
    fifth->data = 10;
    fifth->next = second;

    Node* check = LoopedOrNot(&head);
    if(check == NULL)
        cout<<"NULL Terminated Linked List"<<endl;
    else    
        cout<<"Starting node : "<<check->data<<endl;
    return 0;
} 