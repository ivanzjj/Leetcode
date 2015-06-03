class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size ();
        if (sz < 2)    return 0; 
        int sum = 0, ans = 0;
        for (int i=0;i<sz-1;i++){
            sum += (prices[i+1] - prices[i]);
            ans = max (ans, sum);
            if (sum < 0)    sum = 0;
        }
        return ans;
    }
};