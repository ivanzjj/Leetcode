/*
recursion
*/
class Solution {
public:
    int ans;
    void dfs (TreeNode* now, int sum){
        if (now->left == NULL && now->right == NULL){
            ans += sum; return;
        }
        if (now->left != NULL)  dfs (now->left, sum * 10 + now->left->val);
        if (now->right != NULL) dfs (now->right, sum * 10 + now->right->val);
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL)   return 0;
        ans = 0;
        dfs (root, root->val);
        return ans;
    }
};

/*
queue + iteration
*/
class Solution {
public:
    typedef pair<TreeNode*, int> PP;
    
    int sumNumbers(TreeNode* root) {
        if (root == NULL)   return 0;
        queue<PP> que;
        que.push ({root, root->val});
        int ans = 0;
        
        while (!que.empty()){
            TreeNode *now = que.front().first;
            int sum = que.front().second; que.pop();
            if (now->left == NULL && now->right == NULL){
                ans += sum;
            }
            if (now->left != NULL){
                que.push ({now->left, sum*10+now->left->val});
            }
            if (now->right != NULL)
                que.push ({now->right, sum*10+now->right->val});
        }
        return ans;
    }
};