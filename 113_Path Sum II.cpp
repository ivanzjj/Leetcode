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
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void dfs (TreeNode* now, int sum){
        if (now->left == NULL && now->right == NULL){
            if (sum == now->val){
                tmp.push_back (now->val);
                ans.push_back (tmp);
                tmp.pop_back ();
            }
            return;
        }
        tmp.push_back (now->val);
        if (now->left)  dfs (now->left, sum - now->val);
        if (now->right) dfs (now->right, sum - now->val);
        tmp.pop_back ();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear (); tmp.clear ();
        if (root == NULL)   return ans;
        dfs (root, sum);
        return ans;
    }
};