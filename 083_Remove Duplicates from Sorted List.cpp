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
        ListNode *p, *q;
        p = head;
        while (p){
            q = p->next;
            while (q){
                if (q->val != p->val)   break;
                q = q->next;
            }
            p->next = q;
            p = p->next;
        }
        return head;
    }
};