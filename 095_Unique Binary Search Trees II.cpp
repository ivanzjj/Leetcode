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
    vector<TreeNode*> dfs (int l , int r){
        vector<TreeNode*> vec;
        if (l > r){
            vec.push_back (NULL); return vec;
        }
        vector<TreeNode* > left, right;
        TreeNode *now;        
        for (int i=l;i<=r;i++){
            left = dfs(l, i-1);
            right = dfs (i+1,r);
            int left_sz = left.size (), right_sz = right.size ();
            for (int x=0;x<left_sz;x++) for (int y=0;y<right_sz;y++){
                now = new TreeNode (i);
                now->left = left[x];
                now->right = right[y];
                vec.push_back (now);
            }
        }
        return vec;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs (1, n);
    }
};