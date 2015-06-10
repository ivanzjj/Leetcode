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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> vec;
        
        while (root != NULL){
            vec.push_back (root->val);
            st.push (root);
            root = root->left;
        }
        
        while (!st.empty()){
            TreeNode *now = st.top (); st.pop();
            if (now->right != NULL){
                now = now->right;
                while (now){
                    vec.push_back (now->val);
                    st.push (now);
                    now = now->left;
                }
            }
        }
        return vec;
    }
};


/*Morris Traverse*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *prev = NULL;
        vector<int> ans;
        
        while (cur){
            if (cur->left == NULL){
                ans.push_back (cur->val);
                cur = cur->right;
            }
            else{
                prev = cur->left;
                while (prev->right != NULL && prev->right!=cur) prev = prev->right;
                if (prev->right == cur){
                    // second
                    prev->right = NULL;        
                    cur = cur->right;
                }   
                else{
                    // first;
                    ans.push_back (cur->val);            
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
};
