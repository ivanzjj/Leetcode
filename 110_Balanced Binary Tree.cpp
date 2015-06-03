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
    bool fail;
    int dfs (TreeNode *now){
        if (now == NULL)    return 0;
        if (fail)   return 0;   
        int dep1 = dfs (now->left);
        if (fail)   return 0;
        int dep2 = dfs (now->right);
        if (fail)   return 0;
        if (abs (dep1 - dep2) > 1) {
            fail = true; return 0;
        }
        return max (dep1, dep2) + 1;
    }
    bool isBalanced(TreeNode* root) {
        fail = false;
        if (root == NULL)   return true;
        int dep1 = dfs (root->left);
        if (fail)   return false;
        int dep2 = dfs (root->right);
        if (fail)   return false;
        if (abs(dep1 - dep2) > 1)   return false;
        return true;
    }   
};