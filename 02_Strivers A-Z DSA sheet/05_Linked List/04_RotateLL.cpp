// https://leetcode.com/problems/rotate-list/description/

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
    int len = 0;
    ListNode *tail = NULL;
    ListNode *reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL;
        tail = head;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            len++;
        }
        return prev;
    }
    void insertLast(ListNode *node){
        tail->next = node;
        tail = node;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        head = reverse(head);
        k = k%len;
        ListNode *curr = head, *next = head;
        for(int i = 0; i < k; i++){
            next = curr->next;
            curr->next = NULL;
            insertLast(curr);
            curr = next;
        }
        return reverse(next);
    }
};

int main(){
    
    return 0;
}