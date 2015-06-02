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
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode *> st;
        TreeNode *tmp;
        vector <int> ans;
        if (root == NULL)   return ans;
        while (root != NULL)    st.push (root), root = root->left;
        while (!st.empty()){
            tmp = st.top(); st.pop();
            ans.push_back (tmp->val);
            if (tmp->right != NULL){
                tmp = tmp->right;
                while (tmp != NULL) st.push (tmp), tmp = tmp->left;
            }
        }
        return ans;
    }
};