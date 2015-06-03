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
        TreeLinkNode *now = root, *nxt, *prev;
        while (now){
            nxt = NULL; prev = NULL;
            while (now){
                if (now->left){
                    if (nxt == NULL)    nxt = now->left;
                    if (prev != NULL)   prev->right->next = now->left;
                    now->left->next = now->right;
                }
                prev = now;
                now = now->next;
            }
            now = nxt;
        }
    }
};