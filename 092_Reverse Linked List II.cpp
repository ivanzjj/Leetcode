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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *dummy = new ListNode (-1), *p, *q, *last, *r;
        dummy->next = head;
        p = dummy;
        for (int i=0;i<m-1;i++) p = p->next;
        q = p->next;
        last = q;
        p->next = NULL;
        for (int i=0;i<n-m+1;i++){
            r = q->next;
            q->next = p->next;
            p->next = q;
            q = r;
        }
        last->next = q;
        return dummy->next;
    }
};