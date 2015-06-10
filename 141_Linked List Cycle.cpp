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
    bool hasCycle(ListNode *head) {
        if (head == NULL)   return false;
        ListNode *one = head, *two = head;
        while (true){
            if (two == NULL || two->next==NULL) return false;
            one = one->next;
            two = two->next->next;
            if (one == two) return true;
        }
    }
};
