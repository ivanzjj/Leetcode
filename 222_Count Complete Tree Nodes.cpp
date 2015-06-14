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
    void dfs (TreeNode *now, int& sum){
        if (now == NULL)    return;
        if (now->left==NULL && now->right==NULL)    {
            sum++; return;
        }
        
        int left_dep = 0, right_dep = 0;
        TreeNode *_left = now->left, *_right = now->left;
        while (_right != NULL)  _left = _left->left, _right = _right->right, left_dep++;
        if (_left == NULL){
            left_dep--;
            sum += (1 << left_dep);
            TreeNode *tmp = now->right;
            while (tmp) tmp = tmp->left, right_dep++;
            if (left_dep == right_dep)  return;
            dfs (now->right, sum);
        }
        else{
            dfs (now->left, sum);
        }
    }
    int countNodes(TreeNode* root) {
        if (root == NULL)   return 0;
        int sum = 0;
        dfs (root, sum);
        TreeNode *tmp = root;
        int dep = 0;
        while (tmp) tmp = tmp->left, dep++;
        dep--;
        return (1 << dep) - 1 + sum;
    }
};