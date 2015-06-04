class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        int n = dict.size ();
        int slen = s.length ();
        vector<bool> dp(slen+1,false);
        dp[0] = true;
        for (int i=0;i<slen;i++) if (dp[i]){
            for (int j=1;i+j<=slen;j++){
                if (dict.find( s.substr (i,j) )!=dict.end())    dp[i + j] = true;
            }
        }
        return dp[slen];
    }
};