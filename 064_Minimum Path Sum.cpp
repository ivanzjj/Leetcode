class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size (), C = grid[0].size ();
        vector <int> dp (C, 0);
        dp[0] = grid[0][0];
        for (int i=1;i<C;i++)   dp[i] = dp[i-1] + grid[0][i];
        for (int i=1;i<R;i++){
            dp[0] += grid[i][0];
            for (int j=1;j<C;j++)
                dp[j] = min (dp[j], dp[j-1]) + grid[i][j];
        }
        return dp[C-1];
    }
};