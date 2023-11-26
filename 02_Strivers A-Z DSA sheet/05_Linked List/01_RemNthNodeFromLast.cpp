// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *node = head;
        head = dummy;
        for(int i = 1; i <= n; i++) node = node->next;
        while(node != NULL){
            dummy = dummy->next;
            node = node->next;
        }
        dummy->next = dummy->next->next;
        return head->next;
    }
};

int main(){
    
    return 0;
}