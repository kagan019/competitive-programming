/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *insert(ListNode *h, ListNode *e, ListNode* v) {
        if (h == nullptr || v == nullptr)
            return nullptr;
        if (v->val < h->val) {
            v->next = h;
            return v;
        }
        ListNode *cur = h;
        while (cur != e) {
            
            if (cur->next == e || v->val < cur->next->val) {
                v->next = cur->next;
                cur->next = v;
                return h;
            }
            cur = cur->next;
            
        }
        return h;
    }
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        for (ListNode *cur = head; cur->next != nullptr;) {
            
            ListNode *x = cur->next;
            cur->next = cur->next->next;
            head = insert(head, cur->next, x);
            if (cur->next == x)
                cur = cur->next;
        }
        return head;
        
    }
};
