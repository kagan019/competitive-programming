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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode ln(-1);
        ListNode *head = &ln;
        ListNode *cur = head;
        while(true) {
            // cur is 1 behind position of new node to be created
            if (l1 == nullptr && l2 == nullptr)
                break;
            int s1 = 0;
            if (l1 != nullptr) {
                s1 = l1->val;
                l1 = l1->next;
            }
            int s2 = 0;
            if (l2 != nullptr) {
                s2 = l2->val;
                l2 = l2->next;
            }
            int s = s1 + s2 + carry;
            carry = s/10; s %= 10;
            ListNode k;
            cur->next = new ListNode(s);
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return head->next;
    }
};
