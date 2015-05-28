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
    void reverse_link (ListNode* &front,ListNode* &tail){
        ListNode *p = NULL, *q = front, *r;
        tail = front;
        while (q != NULL){
            r = q->next;
            q->next = p;
            p = q; q = r;
        }
        front = p;
    }
	
	/*reverse using pre-insert
	void reverse_link (ListNode* &front,ListNode* &tail){
        ListNode *head = NULL, *p = front, *q;
        while (p){
            q = p->next;
            p->next = head;
            if (head == NULL)   tail = p;
            head = p;
            p = q;
        }
        front = head;
    }
	*/
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode tt (0), *dummy = &tt; dummy->next = head;
        ListNode *now = dummy, *end;
        
        for (;;){
            end = now;
            for (int i=0;i<k && end!=NULL;i++)  end = end->next;
            if (end == NULL)    break;
            ListNode *tmp = end;
            end = end->next;
            tmp->next = NULL;
            ListNode *front = now->next;
            reverse_link (front,tmp);
            now->next = front;
            tmp->next = end;
            now = tmp;
        }
        return dummy->next;
        
    }
};