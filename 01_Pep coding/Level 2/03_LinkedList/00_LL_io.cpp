
#include <iostream>
using namespace std;

class ListNode{
    public : 
        int val;
        ListNode *next = nullptr;
        ListNode(int val){
          this->val = val;
        }
};

void LLTraversal(ListNode *head){
    ListNode *current = head;
    while(current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    ListNode *dummy = new ListNode(-1); 
    ListNode *prev = dummy;
    while (n-- > 0){
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    
    return 0;
}  