class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& maze) {
        int R = maze.size ();
        if (!R) return 0;
        int C = maze[0].size ();
        if (!C) return 0;
        vector<int> dp(C,-1);
        dp[C-1] = max (1,1-maze[R-1][C-1]);
        for (int j=C-2;j>=0;j--){
            dp[j] = max (1, dp[j + 1] - maze[R-1][j]);
        }
        for (int i=R-2;i>=0;i--){
            dp[C-1] = max (1, dp[C-1] - maze[i][C-1]);
            for (int j=C-2;j>=0;j--){
                dp[j] = max (1,min (dp[j], dp[j+1]) - maze[i][j]);
            }
        }
        return dp[0];
    }
};
