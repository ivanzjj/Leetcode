/*
using dynamic programming to prune
*/
class Solution {
public:
    vector <vector<int>> ans;
    vector <int> tmp;
    vector <vector<int>> dp;
    
    int DP(vector<int>&ca, int i, int j){
        if (dp[i][j] != -1) return dp[i][j];
        if (i == 0) return dp[i][j] = 0;
        if (j == 0) return dp[i][j] = 1;
        
        if (ca[i-1] > j)    return dp[i][j] = 0;
        
        dp[i][j] = DP(ca, i-1, j);
        
        if (ca[i - 1] <= j){
            dp[i][j] = dp[i][j] | DP(ca, i, j-ca[i-1]);
        }
        return dp[i][j];
    }
    void go (vector<int>& ca, int i, int j){
        if (dp[i][j] != 1)  return;
        if (j == 0 || i==0){
            ans.push_back (tmp);
            return;
        }
        go (ca, i-1,j);
        tmp.push_back (ca[i-1]);
        go (ca, i, j-ca[i-1]);
        tmp.pop_back ();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end());
        auto it = unique (candidates.begin(), candidates.end());
        candidates.resize (it - candidates.begin());
        int sz = candidates.size ();
        reverse (candidates.begin(), candidates.end());
        
        dp.resize (sz + 1);
        for (int i=0;i<sz+1;i++)    dp[i].resize (target + 1), fill (dp[i].begin(), dp[i].end(), -1);
        dp[0][0] = 1;
        dp[sz][target] = DP(candidates, sz, target);
        
        go (candidates, sz, target);
        return ans;
    }
};