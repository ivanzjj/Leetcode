class Solution {
public:
    inline bool match (char a, char b){
        return a == b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length (),len2 = s2.length (), len3 = s3.length ();
        if (len1 + len2 != len3)    return false;
        vector<bool> dp(len2+1,false);
        dp[0] = true;
        for (int j=1;j<=len2;j++) 
            if (s2[j-1] == s3[j-1])   dp[j] = true;
            else            break;
        for (int i=1;i<=len1;i++){
            dp[0] = dp[0] && match (s1[i-1], s3[i-1]);
            for (int j=1;j<=len2;j++){
                dp[j] = dp[j] && match (s1[i-1], s3[i+j-1]);
                dp[j] = dp[j] || (dp[j-1] && match (s2[j-1], s3[i+j-1]));
            }
        }
        return dp[len2];
    }
};