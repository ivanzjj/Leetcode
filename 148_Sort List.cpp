/*
 quick sort
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)   return NULL;
        if (head->next == NULL) return head;
        
        ListNode h1(-1), h2(-1),h3(-1),*left=&h1, *right=&h2, *mid =&h3, *p;
        int val = head->val;
        for (p=head;p;p=p->next){
            if (p->val == val){
                mid->next = p;
                mid = mid->next;
            }
            else if (p->val < val){
                left->next = p;
                left = left->next;
            }
            else{
                right->next = p;
                right = right->next;
            }
        }
        mid->next = left->next = right->next = NULL;
        ListNode *new_head, *tmp;
        new_head = sortList (h1.next);
        tmp = new_head;
        if (tmp == NULL)    new_head = h3.next, tmp = h3.next;
        else{
            while (tmp->next != NULL)   tmp = tmp->next;
            tmp->next = h3.next;
        }
        mid->next = sortList (h2.next);
        return new_head;
    }
};


/*
merge sort
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *one = head, *two = head->next, *second_part;
        while (two != NULL && two->next != NULL)    one = one->next, two = two->next->next;
        second_part = one->next;
        one->next = NULL;
        ListNode *left, *right;
        left = sortList (head);
        right = sortList (second_part);
        ListNode h1(-1), *p = &h1;
        while (left!=NULL || right!=NULL){
            if (left==NULL || (right!=NULL && left->val > right->val)){
                p->next = right;
                right = right->next;
                p = p->next;
            }
            else {
                p->next = left;
                left = left->next;
                p = p->next;
            }
        }
        return h1.next;
    }
};
