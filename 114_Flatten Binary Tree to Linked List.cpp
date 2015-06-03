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
    typedef pair<TreeNode*, TreeNode*> PP;
    PP dfs (TreeNode *now){
        PP res = {NULL, NULL};
        TreeNode *_left = now->left, *_right = now->right;
        now->left = NULL;
        TreeNode *tmp = now;
        if (_left != NULL){
            res = dfs (_left);
            tmp->right = res.first;
            tmp = res.second;
        }
        if (_right != NULL){
            res = dfs (_right);
            tmp->right = res.first;
            tmp = res.second;
        }
        tmp->right = NULL;
        return {now,tmp};
    }
    void flatten(TreeNode* root) {
        if (root == NULL)   return;
        PP res = dfs (root);
    }
};