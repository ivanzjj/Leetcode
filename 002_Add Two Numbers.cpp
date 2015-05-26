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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode (-1), *p;
        int c = 0;
        for (p = head; l1 || l2 || c;){
            int x = (l1?l1->val:0) + (l2?l2->val:0) + c;
            c = x / 10; x %= 10;
            p = p->next = new ListNode (x);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head->next;
    }
};