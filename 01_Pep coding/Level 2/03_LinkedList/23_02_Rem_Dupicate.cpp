//Using remove first add last

// Sample Input
//     12
//     1 1 1 4 5 6 6 7 8 9 9 9
// Sample Output
//     1 4 5 6 7 8 9

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

static Node *th = nullptr , *tt = nullptr;
void addLast(Node *node){
    if(tt == nullptr){
        th = tt = node ;
    }
    else{
        tt->next = node ;
        tt = node ;
   }
}

Node* remDup(Node *head){
    if(!head || !head->next)
        return head;
    
    Node *curr = head;
    while(curr){
        Node *next = curr->next;
        curr->next = nullptr;
        if(tt == nullptr || tt->data != curr->data){
            addLast(curr);
        }
        curr = next;
    }
    return th;
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

    Node *ans = remDup(dummy->next);
    LLTraversal(ans);    
    return 0;
}  