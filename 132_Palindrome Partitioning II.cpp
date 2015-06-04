class Solution {
public:
    vector<vector<int>> dp;
    vector<int> f;
    
    int DP (int len){
        if (f[len] != -1)  return f[len];
        f[len] = INT_MAX;
        int sz = dp[len - 1].size ();
        for (int i=0;i<sz;i++){
            f[len] = min (f[len], DP(dp[len-1][i]) + 1);
        }
        return f[len];
    }    
    int minCut(string s) {
        int slen = s.length ();
        if (slen < 2)  return 0;
        dp.resize (slen);
        for (int i=0;i<slen;i++)    dp[i].resize (0);
        
        for (int i=0;i<slen;i++){
            int low = i, high = i+1;
            while (low>=0 && high<slen && s[low]==s[high]){
                dp[high].push_back (low); low--, high++;
            }
            dp[i].push_back (i);
            low = i-1, high = i + 1;
            while (low>=0 && high<slen && s[low]==s[high])
                dp[high].push_back (low),low--, high++;
        }
        f.resize (slen+1);
        fill_n (f.begin(), slen+1, -1);
        f[0] = 0;
        return DP(slen) - 1;
    }
};