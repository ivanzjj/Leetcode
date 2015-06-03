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
    bool dfs (TreeNode* root, int sum){
        if (root == NULL)   return sum == 0;
        if (root->left==NULL && root->right==NULL)  return sum == root->val;
        bool ok = false;
        if (root->left) ok = ok || dfs (root->left, sum - root->val);
        if (root->right) ok = ok || dfs (root->right, sum - root->val);
        return ok;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)   return false;
        return dfs (root, sum);
    }
};