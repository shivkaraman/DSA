
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node (int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};


Node* deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node *dummyH = new Node(-1);
    dummyH->next = head;
    head->prev = dummyH;
    while(head){
        if(head->data != k){
            head = head->next;
            continue;
        }
        head->prev->next = head->next;
        if(head->next != NULL) head->next->prev = head->prev;
        head = head->next;
    }
    return dummyH->next;
}

int main(){
    
    return 0;
}