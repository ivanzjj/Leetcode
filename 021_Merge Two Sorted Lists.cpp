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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = new ListNode (-1), *tmp;
        tmp = head;
        while (l1 || l2){
            if (l1==NULL || (l2!=NULL && l2->val < l1->val)){
                tmp->next = l2; l2=l2->next;
            }
            else{
                tmp->next = l1; l1=l1->next;
            }
            tmp = tmp->next;
        }
        return head->next;
    }
};