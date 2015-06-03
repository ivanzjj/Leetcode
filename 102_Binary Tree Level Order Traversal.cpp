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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> que[2];
        int pre = 0, now = 1;
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root == NULL)   return ans;
        que[now].push (root);
        tmp.push_back (root->val); ans.push_back (tmp);
        
        while (!que[now].empty()){
            pre ^= 1; now ^= 1;
            tmp.clear (); while (!que[now].empty ())    que[now].pop();
            while (!que[pre].empty()){
                TreeNode *cur = que[pre].front (); que[pre].pop();
                if (cur->left != NULL)  que[now].push (cur->left), tmp.push_back (cur->left->val);
                if (cur->right != NULL) que[now].push (cur->right), tmp.push_back (cur->right->val);
            }
            if (tmp.size ())
                ans.push_back (tmp);
        }
        return ans;
    }
};