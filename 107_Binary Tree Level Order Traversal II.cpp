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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)  return ans;
        queue<TreeNode* > st[2];
        int pre = 0 ,now = 1;
        st[now].push (root);
        
        while (!st[now].empty()){
            now ^= 1; pre ^= 1;
            ans.push_back (vector<int>());
            while (!st[now].empty())    st[now].pop();
            while (!st[pre].empty()){
                TreeNode *tmp = st[pre].front(); st[pre].pop();
                ans.back().push_back (tmp->val);
                if (tmp->left)  st[now].push (tmp->left);
                if (tmp->right) st[now].push (tmp->right);
            }
        }
        reverse (ans.begin(), ans.end ());
        return ans;
    }
};