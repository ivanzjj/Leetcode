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
    void reverse_order (ListNode* &root){
        ListNode *head = root, *nxt;
        root = NULL;
        while (head){
            nxt = head->next;
            head->next = root;
            root = head;
            head = nxt;
        }
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next==NULL)   return;
        ListNode *one = head, *two = head->next, *second_part;
        while (two!=NULL && two->next!=NULL){
            one = one->next;
            two = two->next->next;
        }
        second_part = one->next;
        one->next = NULL;
        reverse_order (second_part);
        ListNode *first_part = head, *new_root = new ListNode (-1), *tmp = new_root;
        
        while (first_part || second_part){
            if (first_part) tmp->next = first_part, tmp = tmp->next, first_part = first_part->next;
            if (second_part)    tmp->next = second_part, second_part = second_part->next, tmp = tmp->next;
        }
    }
};
