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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)   return NULL;
        ListNode *new_head = new ListNode (-1);
        ListNode *now = head, *tmp, *new_tmp;
        
        while (now){
            tmp = now;
            now = now->next;
            new_tmp = new_head;
            while (new_tmp->next != NULL && new_tmp->next->val < tmp->val) new_tmp = new_tmp->next;
            tmp->next = new_tmp->next;
            new_tmp->next = tmp;
        }
        return new_head->next;
    }
};
