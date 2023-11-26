
#include <stdio.h>
#include <stdlib.h>

int size = 0;
typedef struct node{
    int data;
    struct node *next;
}node;

node* createNode(int data){
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode; 
}

node* insertFront(node *first, int data){
    node *newNode = createNode(data);
    size++;
    if(first == NULL){
        return newNode;
    }
    newNode->next = first;
    return newNode;
}
node* insertRear(node *first, int data){
    node *newNode = createNode(data);
    size++;
    if(first == NULL)
        return newNode;
    node *temp = first;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return first;
}
node* deleteFirst(node *first){
    if(first == NULL){
        printf("Empty linked list\n");
        return NULL;
    }
    size--;
    node *temp = first;
    first = first->next;
    free(temp);
    return first;
}
node* deleteLast(node *first){
    if(first == NULL){
        printf("Empty linked list\n");
        return NULL;
    }
    size--;
    if(first->next == NULL){
        free(first);
        return NULL;
    }
    node *temp = first, *temp2 = first->next;
    while(temp2->next != NULL){
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next == NULL;
    free(temp2);
    return first;
}

void display(node *first){
    if(first == NULL){
        printf("Empty linked list\n");
        return;
    }
    node *temp = first;
    printf("Linked List : ");
    while(temp){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* insertAtPosition(node *first, int pos, int data){
    if(pos == 1){
        return insertFront(first, data);
    }
    if(first == NULL){
        printf("Empty linked list\n");
        return NULL;
    }
    if(pos <= 0 || pos > size+1){
        printf("Invalid position\n");
        return first;
    }
    if(pos == size + 1){
        return insertRear(first, data);
    }
    node *temp = first;
    while(pos - 2 > 0){
        temp = temp->next;
        pos--;
    }
    node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
    return first;
}

node* deleteAtPosition(node *first, int pos){
    if(first == NULL){
        printf("Empty linked list\n");
        return NULL;
    }
    if(pos <= 0 || pos > size){
        printf("Invalid position\n");
        return first;
    }
    if(pos == 0)
        return deleteFirst(first);
    if(pos == size)
        return deleteLast(first);
    node *temp = first;
    while(pos - 2 > 0){
        temp = temp->next;
        pos--;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    size--;
    return first;
}
node* deleteByKey(node *first, int key){
    if(first == NULL){
        printf("Empty List\n");
        return NULL;
    }
    if(key == first->data){
        return deleteFirst(first);
    }
    node *temp = first, *prev;
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Key not found\n");
        return first;
    }
    prev->next = temp->next;
    free(temp);
    return first;
}

node *createOrderedList(node *first){
    int data, choice = 1;
    while(choice){
        printf("Enter data : ");
        scanf("%d", &data);
        node *newNode = createNode(data);
        node *temp = first, *prev;
        if(first == NULL || data < temp->data){
            first = insertFront(first, data);
            goto input;
        }
        while(temp != NULL && data > temp->data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            insertRear(first, data);
        }
        newNode->next = temp;
        prev->next = newNode;
        input :
        printf("Do you want to create new node(1-Yes 0-No) : ");
        scanf("%d", &choice);
    }
    return first;
}

int main(){
    int data, choice, pos, *ordered = NULL;
    node *first = NULL;
    while(1){
        printf("\n1.Insert first\n2.Insert last\n3.Delete First\n4.Delete Rear\n5.Insert at position\n6. Delete at position\n7.Delete by key\n8.Create new ordered list\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                first = insertFront(first, data);
                display(first);
                break;
            case 2:
                printf("Enter data : ");
                scanf("%d", &data);
                first = insertRear(first, data);
                display(first);
                break;
            case 3:
                first = deleteFirst(first);
                display(first);
                break;
            case 4:
                first = deleteLast(first);
                display(first);
                break;
            case 5:
                printf("Enter data : ");
                scanf("%d", &data);
                printf("Enter position : ");
                scanf("%d", &pos);
                first = insertAtPosition(first, pos, data);
                display(first);
                break;
            case 6:
                printf("Enter position : ");
                scanf("%d", &pos);
                first = deleteAtPosition(first, pos);
                display(first);
                break;
            case 7:
                printf("Enter key : ");
                scanf("%d", &data);
                first = deleteByKey(first, data);
                display(first);
                break;
            case 8:
                ordered = createOrderedList(ordered);
                display(ordered);
                break;
            default:
                return 0;
        }
    }

    return 0;
}