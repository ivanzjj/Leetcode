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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *sa = headA, *sb = headB;
        if (headA == NULL || headB == NULL) return NULL;
        bool first_a = true, first_b = true;
        while (sa!=NULL || sb!=NULL || first_a || first_b){
            if (sa == NULL) sa = headB, first_a = false;
            if (sb == NULL) sb = headA, first_b = false;
            if (sa == sb)   return sa;
            sa = sa->next; sb = sb->next;
        }
        return NULL;
    }
};
