class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void dfs (int now , int n, int cnt, int k){
        if (now == n+1){
            if (cnt != k)   return;
            ans.push_back (tmp);
            return;
        }
        dfs (now+1, n, cnt, k);
        tmp.push_back (now);
        dfs (now+1, n, cnt+1, k);
        tmp.pop_back ();
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear (); tmp.clear ();
        dfs (1, n, 0, k);
        return ans;
    }
};