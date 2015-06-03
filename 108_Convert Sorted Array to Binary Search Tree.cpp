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
    TreeNode* dfs(vector<int>& nums, int l, int r){
        if (l > r)  return NULL;
        int mid = (l + r) >> 1;
        TreeNode* now = new TreeNode (nums[mid]);
        now->left = dfs (nums,l, mid-1);
        now->right = dfs (nums, mid+1, r);
        return now;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs (nums, 0, nums.size ()-1);
    }
};