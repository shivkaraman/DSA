
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

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};


class Solution {
public:
    ListNode *tempH = NULL, *tempT = NULL;
    void addFirst(ListNode *node){
        if(tempH == NULL) tempH = tempT = node;
        else{
            node->next = tempH;
            tempH = node;
        } 
    }
    int length(ListNode *head){
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = length(head);
        int iter = len/k;

        ListNode *newHead = NULL, *node = head;
        ListNode *prev = NULL, *next = NULL;
        for(int i = 0; i < iter; i++){
            for(int j = 0; j < k; j++){
                next = node->next;
                node->next = NULL;
                addFirst(node);
                node = next;
            }
            if(newHead == NULL) newHead = tempH;
            else prev->next = tempH;
            prev = tempT;
            tempH = tempT = NULL;
        }
        if(prev)prev->next = node;
        return newHead;
    }
};
int main(){
    
    return 0;
}