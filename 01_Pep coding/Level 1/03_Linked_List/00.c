
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void llTraversal(node *head){
    if(head == NULL){
        printf("Empty linked list\n");
        return;
    }
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int choice = 1;
    node *head, *second, *third;
    head = createNode(10);
    second = createNode(20);
    third = createNode(30);

    head->next = second;
    second->next = third;

    llTraversal(head);
    return 0;
}