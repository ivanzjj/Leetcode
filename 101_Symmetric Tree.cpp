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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode *> st;
        if (root == NULL)   return true;
        st.push (root->left); st.push (root->right);
        TreeNode *_left, *_right;
        
        while (!st.empty ()){
            _right = st.top (), st.pop();
            _left = st.top(), st.pop();
            if ((_left==NULL && _right!=NULL) || (_left!=NULL && _right==NULL)) return false;
            if (_left!=NULL && _right!=NULL){
                if (_left->val != _right->val)  return false;
                st.push (_left->left); st.push (_right->right);
                st.push (_left->right); st.push (_right->left);
            }
        }
        return true;
    }
};