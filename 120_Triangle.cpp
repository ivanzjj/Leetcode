class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int R = triangle.size ();
        if (R == 0) return 0;
        vector<int> dp (R, 0);
        dp[0] = triangle[0][0];
        for (int i=1;i<R;i++){
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j=i-1;j>0;j--){
                dp[j] = min (dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        int ans = INT_MAX;
        for (int i=0;i<R;i++)   ans = min (ans, dp[i]);
        return ans;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int R = triangle.size ();
        if (!R) return 0;
        for (int i=1;i<R;i++){
            for (int j=0;j<=i;j++){
                int _min = INT_MAX;
                if (j != i) _min = min (_min, triangle[i-1][j]);
                if (j != 0) _min = min (_min, triangle[i-1][j-1]);
                triangle[i][j] += _min;
            }
        }
        int ans = INT_MAX;
        for (int i=0;i<R;i++)   ans = min (ans, triangle[R-1][i]);
        return ans;
    }
};
