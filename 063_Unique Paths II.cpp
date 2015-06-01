class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size (), C = obstacleGrid[0].size ();
        vector <int> dp(C,0);
        for (int j=0;j<C;j++)  
            if(obstacleGrid[0][j] == 1)  break;
            else        dp[j] = 1;
        for (int i=1;i<R;i++){
            if (obstacleGrid[i][0] == 1)    dp[0] = 0;
            for (int j=1;j<C;j++){
                if (obstacleGrid[i][j] == 1)    dp[j] = 0;
                else        dp[j] += dp[j-1];
            }
        }
        return dp[C-1];
    }
};