class Solution {
public:
    vector <string> ans;
    
    void dfs (string &s,int idx,int left, int right){
        if (left == 0 && right == 0){
            ans.push_back (s);
            return;
        }
        if (left){
            s[idx] = '(';
            dfs (s, idx+1,left-1,right);
        }
        if (right && left <= right-1){
            s[idx] = ')';
            dfs (s, idx+1, left, right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s (2*n, ' ');
        dfs (s,0,n,n);
        return ans;
    }
};