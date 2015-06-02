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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less_head = new ListNode (-1), *great_head = new ListNode (-1);
        ListNode *p = less_head, *q = great_head;
        while (head){
            if (head->val < x)  p->next = head, p = p->next;
            else                q->next = head, q = q->next;
            head = head->next;
            p->next = q->next = NULL;
        }
        p->next = great_head->next;
        return less_head->next;
    }
};