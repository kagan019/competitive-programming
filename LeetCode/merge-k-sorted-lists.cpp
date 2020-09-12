#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        
        ListNode* cur[lists.size()];
        for (int i = 0; i < lists.size(); i++) {
            cur[i] = lists[i];
        }
        
        auto cmpnodes = [](ListNode* a, ListNode* b){ 
            if (!a) return true;
            if (a && !b) return false;
            return a->val > b->val; 
        };
        make_heap(cur, cur + lists.size(), cmpnodes);
        
        ListNode* merged = new ListNode(-1);
        ListNode* head = merged;
        ListNode* smaller = cur[0];
        while (smaller) {
            merged->next = smaller;
            merged = merged->next;
            
            pop_heap(cur, cur + lists.size(), cmpnodes);
            
            cur[lists.size() - 1] = cur[lists.size() - 1]->next;
            push_heap(cur, cur + lists.size(), cmpnodes);
            
            smaller = cur[0];
        } 
        
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};