class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<string> tmp;
    
    void dfs (int i, int len, string& s){
        if (i >= len){
            ans.push_back (tmp);
            return;
        }
        for (int j=i;j<len;j++) if (dp[i][j]){
            tmp.push_back (s.substr(i,j-i+1));
            dfs (j+1,len,s);
            tmp.pop_back ();
        }
    }
    vector<vector<string>> partition(string s) {
        int slen = s.length ();
        ans.clear ();
        if (slen == 0)  return ans;
        dp.resize (slen);
        for (int i=0;i<slen;i++)    dp[i].resize (slen), fill_n (dp[i].begin(), slen, false);
        
        for (int i=0;i<slen;i++){
            dp[i][i] = true;
            if (i-1>=0) dp[i][i-1] = true;
        }
        for (int len=2;len<=slen;len++){
            for (int i=0,j;i+len<=slen;i++){
                j = i + len - 1;
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        tmp.clear ();
        dfs (0, slen, s);
        return ans;
    }
};