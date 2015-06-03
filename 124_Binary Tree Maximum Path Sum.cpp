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
    int ans;
    int dfs (TreeNode* now){
        int res = 0, best = 0, t;
        if (now->left){
            res = max (res, best + (t=dfs (now->left)));
            best = max (best, t);
        }
        if (now->right){
            res = max (res, best + (t=dfs (now->right)));
            best = max (best, t);
        }
        res += now->val;
        ans = max (ans, res);
        return best + now->val;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        if (root == NULL)   return ans;
        dfs (root);
        return ans;
    }
};