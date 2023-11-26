
// 1. You are given K list of lists, where each list is sorted.
// 2. You are required to complete the body of mergeKSortedLists function. The function is expected to merge k sorted lists to 
//    create one sorted list.

// Constraints
// Space complextiy = O(k)
// Time complexity = nlogk
// where k is the number of lists and n is number of elements across all lists.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode *next;

    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
};


class MyComparator{
public: 
    bool operator()(ListNode *node1, ListNode *node2){
        return node1->val > node2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    
    priority_queue<ListNode*, vector<ListNode*>, MyComparator> pq;
    for(int i = 0; i < lists.size(); i++){
        if(lists[i]) pq.push(lists[i]);
    }
    while(!pq.empty()){
        ListNode *node = pq.top();
        pq.pop();
        
        prev->next = node;
        prev = node;
        if(node->next) pq.push(node->next);
    }
    return dummy->next;
}

void display(ListNode *node){
    while(node){
        cout << node->val << "->";
        node = node->next;
    }
}

int main(){
    vector<ListNode *> lists;
    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        int n;
        cin >> n;
        while(n--){
            int x;
            cin >> x;
            prev->next = new ListNode(x);
            prev = prev->next;
        }
        lists.push_back(dummy->next);
    }
    ListNode *ans = mergeKLists(lists);
    display(ans);
}