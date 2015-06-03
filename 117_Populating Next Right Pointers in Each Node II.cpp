/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *now = root;
        if (!root)  return;
        
        TreeLinkNode* nxt, *prev;
        while (now){
            nxt = NULL; prev = NULL;
            while (now){
                if (now->left){
                    if (nxt == NULL)    nxt = now->left;
                    if (prev != NULL)   prev->next = now->left;
                    prev = now->left;
                }
                if (now->right){
                    if (nxt == NULL)    nxt = now->right;
                    if (prev != NULL)   prev->next = now->right;
                    prev = now->right;
                }
                now = now->next;
            }
            now = nxt;
        }
    }
};