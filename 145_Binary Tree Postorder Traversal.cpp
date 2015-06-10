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
    typedef pair<TreeNode*, int> PP;
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)   return ans;
        stack<PP> st;
        st.push ({root,0});
        while (!st.empty ()){
            TreeNode *now = st.top().first;
            int flag = st.top().second;
            if (flag == 0){
                st.top().second = 1;
                if (now->left)  st.push ({now->left,0});
            }
            else if (flag == 1){
                st.top().second = 2;
                if (now->right) st.push ({now->right,0});
            }
            else{
                ans.push_back (now->val);
                st.pop();
            }
        }
        return ans;
    }
};
