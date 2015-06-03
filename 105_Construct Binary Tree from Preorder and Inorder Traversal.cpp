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
    typedef vector<int>::iterator ite;
    TreeNode* dfs (ite pre_begin, ite pre_end, ite in_begin, ite in_end){
        if (pre_begin == pre_end)   return NULL;
        ite sep = in_begin;
        for (;sep != in_end && *pre_begin != *sep; sep++);
        if (sep == in_end)  return NULL;
        int sz = sep - in_begin;
        TreeNode *root = new TreeNode (*pre_begin);
        root->left = dfs (pre_begin+1,pre_begin+1+sz,in_begin,sep);
        root->right = dfs (pre_begin+1+sz,pre_end,sep+1,in_end);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs (preorder.begin (), preorder.end (), inorder.begin(), inorder.end ());
    }
};