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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)  return ans;
        stack<TreeNode *> st[2];
        int pre = 0, now = 1;
        st[now].push (root);
        
        int left_to_right = 1;
        
        while (!st[now].empty ()){
            ans.push_back (vector<int>());
            now ^= 1; pre ^= 1;
            while (!st[now].empty ())   st[now].pop();
            while (!st[pre].empty ()){
                TreeNode *tmp = st[pre].top(); st[pre].pop();
                ans.back ().push_back (tmp->val);            
                if (left_to_right){
                    if (tmp->left)  st[now].push (tmp->left);
                    if (tmp->right) st[now].push (tmp->right);
                }
                else{
                    if (tmp->right) st[now].push (tmp->right);
                    if (tmp->left) st[now].push (tmp->left);
                }
            }
            left_to_right ^= 1;
        }
        
        return ans;
    }
};