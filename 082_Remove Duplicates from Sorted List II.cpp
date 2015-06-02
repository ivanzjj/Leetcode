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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode (-1), *p, *q;
        dummy->next = head;
        p = dummy;
        
        while (p->next){
            q = p->next;
            int cnt = 1;
            while (q->next && q->val == q->next->val)   cnt++, q = q->next;
            if (cnt == 1)   p->next = q, p = q;
            else            p->next = q->next;
        }
        return dummy->next;
    }
};