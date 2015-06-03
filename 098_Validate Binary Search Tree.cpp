/**
PAY ATTENTION:
1, the node's value maybe INT_MIN or INT_MAX, so watch out overflow when doing now->val - 1 and now->val + 1
2, the initial value of _left and _right

OVERFLOW is the edge case
 */
class Solution {
public:
    bool dfs (TreeNode *now, int _min, int _max){
        if (now == NULL)    return true;
        if (_min > _max)    return false;
        if (now->val < _min || now->val > _max) return false;
        bool _left = now->left == NULL , _right = now->right == NULL;
        if (now->val != INT_MIN)    _left = dfs (now->left, _min, now->val-1);
        if (now->val != INT_MAX)    _right = dfs (now->right, now->val+1, _max);
        return _left && _right;
    }
    bool isValidBST(TreeNode* root) {
        return dfs (root, INT_MIN, INT_MAX);
    }
};