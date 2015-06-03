/*in-order traverse*/

/*stack + iteration
time complexity : O(N)
space complexity : O(logN)
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *now = root, *p, *q;
        while (now != NULL) st.push (now),now = now->left;
        p = NULL;
        bool first = true; 
        TreeNode *left = NULL, *right = NULL;
        while (!st.empty ()){
            q = st.top (); st.pop();
            if (p != NULL && p->val > q->val){
                if (first)  left = p, first = false, right = q;
                else        right = q;
            }
            if (q->right != NULL){
                now = q->right;
                while (now != NULL) st.push (now), now = now->left;
            }
            p = q;
        }
        swap (left->val, right->val);
    }
};

/*
Morris traverse
time complexity : O(N)
space complexity : O(1)
*/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *now,*tmp,*prev;
        now = root; prev = NULL;
        bool first = true;
        TreeNode *left = NULL, *right = NULL;
        
        while (now != NULL){
            if (now->left == NULL){
                if (prev != NULL && prev->val > now->val){
                    if (first)  left = prev, right = now, first = false;
                    else        right = now;
                }
                prev = now;
                now = now->right;
            }
            else{
                tmp = now->left;
                while (tmp->right!=NULL && tmp->right != now)  tmp = tmp->right;
                if (tmp->right == now){
                    if (prev != NULL && prev->val > now->val){
                        if (first)  left = prev, right = now, first = false;
                        else        right = now;
                    }
                    prev = now;
                    tmp->right = NULL, now = now->right;
                }
                else    tmp->right = now, now = now->left;
            }
        }
        swap (left->val, right->val);
    }
};