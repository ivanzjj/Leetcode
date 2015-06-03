/*
stack + iteration
space complexity : O (logN)
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


/*
Morris traverse
space complexity : O (1)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        
        TreeNode *now, *prev;
        now = root;
        while (now != NULL){
            if (now->left == NULL){
                ans.push_back (now->val);
                now = now->right;
            }
            else{
                prev = now->left;
                while (prev->right!=NULL && prev->right != now)  prev = prev->right;
                if (prev->right == now)  ans.push_back (now->val), prev->right = NULL, now = now->right;
                else    prev->right = now, now = now->left;
            }
        }
        return ans;
    }
};