
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

void LLTraversal(Node *head){
    Node *current = head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout << endl;
}

Node *getPivot(Node *head, int pivotIdx){
    if (head == nullptr) return nullptr;

    Node *pivot = head;
    while (pivot && pivotIdx--){
        pivot = pivot->next;
    }

    return pivot;
}

vector<Node*> segPivot(Node *head, int pivotIdx){
    Node *pivot = getPivot(head, pivotIdx);

    Node *smaller = new Node(-1);
    Node *prevS = smaller;

    Node *larger = new Node(-1);
    Node *prevL = larger;

    Node *curr = head;
    int idx = 0;
    while(curr){
        if (idx == pivotIdx); //Do nothing
        else if(curr->data <= pivot->data){
            prevS->next = curr;
            prevS = prevS->next;
        }
        else{
            prevL->next = curr;
            prevL = prevL->next;
        }
        curr = curr->next;
        idx++;
    }
    prevS->next = nullptr;
    pivot->next = nullptr;
    prevL->next = nullptr;

    vector<Node*> vec = {smaller->next, pivot, larger->next};
    return vec;
}

int length(Node *head){
    int count = 0;
    Node *curr = head;
    while(curr){
        curr = curr->next;
        count++;
    }
    return count;
}

vector <Node *> mergeSortedLists(vector <Node *> leftSorted, Node *pivot, vector <Node *> rightSorted){
    Node *head = nullptr, *tail = nullptr;
    if(leftSorted[0] && rightSorted[0]){
        leftSorted[1]->next = pivot;
        pivot->next = rightSorted[0];
        head = leftSorted[0];
        tail = rightSorted[1];
    }

    else if(leftSorted[0] != nullptr){
        leftSorted[1]->next = pivot;
        head = leftSorted[0];
        tail = pivot;
    }

    else if(rightSorted[0] != nullptr){
        pivot->next = rightSorted[0];
        head = pivot;
        tail = rightSorted[1];
    }

    else{
        head = tail = pivot;
    }

    vector <Node *> vec = {head, tail};
    return vec;
}

vector<Node*> quickSort(Node *head){
    if (!head || !head->next){
        vector<Node*> vec = {head, head};
        return vec;
    }
    int len = length(head);
    int pivotIdx = len/2;

    vector<Node*> segratedLists = segPivot(head, pivotIdx);

    vector<Node *> leftSorted = quickSort(segratedLists[0]);
    vector<Node *> rightSorted = quickSort(segratedLists[2]);
    return mergeSortedLists(leftSorted, segratedLists[1], rightSorted);
}

Node *QuickSort(Node *head){
    vector <Node *> ans = quickSort(head);
    return ans[0];
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

    Node *ans = QuickSort(dummy->next);
    LLTraversal(ans);
    return 0;
}  