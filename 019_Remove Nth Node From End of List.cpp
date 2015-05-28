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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode (-1), *first, *second;
        pre->next = head;
        first = second = pre;
        for (int i=0;i<n && second;i++)   second = second->next;
        if (second == NULL)     return pre->next;
        while (second->next != NULL){
            first = first->next; second = second->next;
        }
        first->next = first->next->next;
        return pre->next;
    }
};