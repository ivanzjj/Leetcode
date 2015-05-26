class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bool vis[300] = {false};
        for (int sz = s.length(), low = 0, high = 0; high < sz;){
            while (high < sz && !vis[ s[high] ]){
                vis[ s[high] ] = 1; high++;
            }
            ans = max (ans, high - low);
            vis [ s[low++] ] = 0;
        }
        return ans;
    }
};