class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size ();
        if (sz < 2) return 0;
        int ans = 0;
        for (int i=0;i<sz-1;i++){
            ans += max (0, prices[i+1] - prices[i]);
        }
        return ans;
    }
};