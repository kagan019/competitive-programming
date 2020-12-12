/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* beg, ListNode* end){
        if(beg == end){
            return;
        }
        ListNode* after = end->next;
        ListNode* lastlast = beg;
        ListNode* last = beg->next;
        for(ListNode* current = last->next; current != nullptr && current != after; current=current->next){
            last->next = lastlast;
            lastlast = last;
            last = current;
        }
        last->next = lastlast;
        beg->next = after;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {

        int i = 0;
        ListNode* beginReverse = head;
        ListNode* prevBegin = nullptr;
        ListNode* next;
        for(ListNode* current=head; current != nullptr;current = next){
            next = current->next;
            if(i%k==0)
                beginReverse = current;
            if((i+1)%k==0) {
                reverse(beginReverse, current);
                if(prevBegin == nullptr){
                    head = current;
                }else{
                   prevBegin->next = current;
                }
                prevBegin = beginReverse;
            }
            i++;
        }

        return head;
        
    }
};
