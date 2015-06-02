class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> dp[2];
        if (n == 0){
            dp[0].push_back (0); return dp[0];
        }
        int pre = 0 , now = 1;
        dp[now].push_back (0); dp[now].push_back (1);
        
        for (int i=1;i<n;i++){
            pre ^= 1; now ^= 1;
            dp[now].clear ();
            int sz = dp[pre].size ();
            for (int j=0;j<sz;j++)  dp[now].push_back (dp[pre][j]);
            for (int j=sz-1;j>=0;j--)   dp[now].push_back ((1 << i) + dp[pre][j]);
        }
        return dp[now];
    }
};


class Solution {
public:
    vector<int> grayCode(int n) {
        int MA = (1 << n);
        vector<int> ans;
        for (int i=0;i<MA;i++){
            ans.push_back (i ^ (i >> 1));
        }
        return ans;
    }
};