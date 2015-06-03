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
    TreeNode* dfs (vector<int>& inorder, int x, vector<int>& postorder, int y, int len){
        if (len == 0)   return NULL;
        int sep = x + len - 1;
        for (;sep>=x && inorder[sep] != postorder[y+len-1]; sep--);
        TreeNode *now = new TreeNode (postorder[y + len - 1]);
        now->left = dfs (inorder, x, postorder, y, sep - x);
        now->right = dfs (inorder, sep+1, postorder, y+sep-x, len-sep+x-1);
        return now;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs (inorder, 0, postorder, 0, inorder.size());   
    }
};