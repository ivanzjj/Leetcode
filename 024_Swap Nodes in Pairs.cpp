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
    void go (ListNode* &head){
        if (head == NULL || head->next == NULL) return;
        ListNode *p = head, *q = head->next, *r = NULL;
        if (q)  r = q->next;
        head = q; q->next = p; p->next = r;
        go (p->next);
    }
    ListNode* swapPairs(ListNode* head) {
        go (head);
        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode tt (0), *dummy = &tt; dummy->next = head;
        ListNode *p = dummy;
        ListNode *q, *r;
        while (p->next != NULL && p->next->next != NULL){
            q = p->next; r = q->next;
            q->next = r->next;
            r->next = q;
            p->next = r;
            p = q;
        }
        return dummy->next;
    }
};