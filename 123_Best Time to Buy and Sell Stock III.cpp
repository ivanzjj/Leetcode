class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size ();
        if (sz < 2) return 0;
        int ans = 0, sum = 0;
        vector<int> num(sz, 0);
        for (int i=0;i<sz-1;i++){
            sum += prices[i+1]-prices[i];
            ans = max (ans, sum);
            if (i > 0)  num[i] = max (num[i-1], ans);
            else    num[i] = ans;
            if (sum < 0)    sum = 0;
        }
        sum = 0;
        for (int i=sz-2;i>=0;i--){
            ans = max (ans, sum + num[i]);
            sum += prices[i+1] - prices[i];
            if (sum < 0)    sum = 0;
        }
        return ans;
    }
};