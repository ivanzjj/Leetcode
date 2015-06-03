class Solution {
public:
    vector<int> dp;
    
    int dfs (int n){
        if (n == 0) return dp[n] = 1;
        if (dp[n] != -1)    return dp[n];
        dp[n] = 0;
        for (int i=0;i<n;i++){
            dp[n] += dfs(i)*dfs(n-i-1);
        }
        return dp[n];
    }
    int numTrees(int n) {
        dp.resize (n+1);
        fill_n (dp.begin(), n+1, -1);
        return dfs (n);
    }
};