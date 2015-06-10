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
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = NULL, *p;
        if (head == NULL)   return NULL;
        while (head){
            p = head->next;
            head->next = new_head;
            new_head = head;
            head = p;
        }
        return new_head;
    }
};
