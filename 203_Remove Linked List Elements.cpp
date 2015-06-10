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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode h1(-1), *dummy = &h1, *p;
        dummy->next = head;
        p = dummy;
        while (p->next != NULL){
            if (p->next->val == val)    p->next = p->next->next;
            else                        p = p->next;
        }
        return dummy->next;
    }
};
