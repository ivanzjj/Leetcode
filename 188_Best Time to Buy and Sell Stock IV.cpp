class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size ();
        for (int i=0;i<N-1;i++) prices[i] = prices[i+1] - prices[i];
        N--;
        int ans = 0;
        if (2*k >= N){
            for (int i=0;i<N;i++)   ans += max (prices[i], 0);
            return ans;
        }
        vector<int> f[2] = {vector<int>(k+1,0), vector<int>(k+1,0)};
        vector<int> g[2] = {vector<int>(k+1,0), vector<int>(k+1,0)};
        int pre = 0, now = 1;
        for(int j=1;j<=k;j++)   f[now][j] = max (0,prices[0]), g[now][j] = prices[0];
        
        for (int i=1;i<N;i++){
            pre ^= 1, now ^= 1;
            f[now][0] = 0; 
            for (int j=1;j<=k;j++){
                f[now][j] = max (f[pre][j], max (f[pre][j-1], g[pre][j])+prices[i]);
                g[now][j] = max (f[pre][j-1] + prices[i], g[pre][j] + prices[i]);
            }
        }
        return f[now][k];
    }
};
