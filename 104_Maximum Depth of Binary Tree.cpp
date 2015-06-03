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
    int maxDepth(TreeNode* root) {
        if (root == NULL)   return 0;
        queue<pair<TreeNode*, int>> que;
        que.push ({root, 1});
        int ans = 1;
        while (!que.empty()){
            TreeNode *now = que.front().first;
            int dep = que.front ().second; que.pop();
            ans = max (ans, dep);
            if (now->left)  que.push ({now->left, dep + 1});
            if (now->right) que.push ({now->right, dep + 1});
        }
        return ans;
    }
};