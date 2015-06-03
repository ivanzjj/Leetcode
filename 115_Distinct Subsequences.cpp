class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length (), tlen = t.length ();
        vector<int> dp (tlen+1, 0);
        dp[0] = 1;
        for (int i=1;i<=slen;i++){
            for (int j=tlen;j>=1;j--){
                if (s[i-1] == t[j - 1]){
                    dp[j] += dp[j - 1];
                }
            }
            dp[0] = 1;
        }
        return dp[tlen];
    }
};