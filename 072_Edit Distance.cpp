class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length (), len2 = word2.length ();
        if (len1 == 0)  return len2;
        if (len2 == 0)  return len1;
        vector <int> dp[2] = {vector<int>(len2+1,len2+1), vector<int>(len2+1,len2+1)};
        int pre = 0, now = 1;
        for (int j=0;j<=len2;j++)   dp[now][j] = j;
        for (int i=1;i<=len1;i++){
            pre ^= 1; now ^= 1;
            
            dp[now][0] = i;
            for (int j=1;j<=len2;j++){
                if (word1[i - 1] == word2[j - 1]){
                    dp[now][j] = dp[pre][j - 1];
                }
                else{
                    dp[now][j] = dp[now][j-1];
                    dp[now][j] = min (dp[now][j], dp[pre][j]);
                    dp[now][j] = min (dp[now][j], dp[pre][j-1]);
                    dp[now][j]++;
                }
            }
        }
        return dp[now][len2];
    }
};