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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode *> vec[2] = {vector<TreeNode*>(), vector<TreeNode *>()};
        int pre = 0, now = 1;
        vector<int> ans;
        if (root == NULL)   return ans;
        vec[now].push_back (root);
        while (vec[now].size ()){
            pre ^= 1; now ^= 1;
            ans.push_back (vec[pre].back()->val);
            vec[now].clear ();
            for (auto p : vec[pre]){
                if (p->left)    vec[now].push_back (p->left);
                if (p->right)   vec[now].push_back (p->right);
            }
        }
        return ans;
    }
};
