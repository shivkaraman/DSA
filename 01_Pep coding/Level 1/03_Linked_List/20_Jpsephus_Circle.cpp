/*
N people have have decided to elect a leader by arrayging themselves in a circle and eleminating every Mth position around the circle 
Find which person will be the last person remaining
*/


#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

void LLTraversal(Node **head){
    Node *current = *head;
    do{
        cout<<current->data<<"->";
        current = current->next;
    }while(current != *head);
    cout<<"NULL"<<endl;
}

void JosephusCircle(){
    int N, M;
    cin>>N>>M;
    //Creating circular linked list
    Node *head = new Node;
    Node *node = head;
    head->data = 1;
    for(int i = 2; i <= N; i++){
        node->next = new Node;
        node = node->next;
        node->data = i;
    }
    node->next = head;
    LLTraversal(&head);
    //Eliminating every M-th player 
    for(int i = 1; i<N; i++){
        for(int j = 0; j<M-1; j++){
            node = node->next;
        }
        Node *temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
    cout<<"Last man standing (Josephus Position) : "<<node->data<<endl;
}

int main(){
    JosephusCircle();
    return 0;
}  