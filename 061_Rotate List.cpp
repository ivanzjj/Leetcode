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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)   return head;
        ListNode *p = head, *q = head, *tmp = head;
        int cnt = 0;
        while (tmp && cnt < k) cnt++, tmp = tmp->next;
        if (cnt < k){
            k %= cnt;
        }
        if (k == 0) return head;
        
        for (int i=0;i<k;i++){
            if (q == NULL)  return head;
            q = q->next;
        }
        if (q == NULL)  return head;
        while (q->next != NULL) p = p->next, q = q->next;
        tmp = p;
        p = p->next;
        tmp->next = NULL;
        q->next = head;
        head = p;
        return head;
    }
};