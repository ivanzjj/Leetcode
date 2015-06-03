/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)   return NULL;
        ListNode *one = head, *two = head->next;
        TreeNode* now = NULL;
        if (two == NULL){
            now = new TreeNode (head->val);
            return now;
        }
        while (two->next != NULL && two->next->next != NULL){
            one = one->next;
            two = two->next->next;
        }
        now = new TreeNode (one->next->val);
        ListNode *p = one->next->next;
        one->next = NULL;
        
        now->left = sortedListToBST(head);
        now->right = sortedListToBST (p);
        return now;
    }
};