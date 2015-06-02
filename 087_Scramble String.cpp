class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length () != s2.length ())   return false;
        int len = s1.length ();
        if (len == 1)       return s1 == s2;
        int vis[256] = {0};
        int cnt = 0;
        
        for (int i=0;i<len-1;i++){
            char a = s1[i], b = s2[i];
            if (vis[a] == 0)    cnt++;  vis[a]++;
            if (vis[a] == 0)    cnt--;
            if (vis[b] == 0)    cnt++;  vis[b]--;
            if (vis[b] == 0)    cnt--;
            if (cnt == 0 && isScramble(s1.substr(0,i+1), s2.substr(0,i+1)) && isScramble(s1.substr (i+1), s2.substr (i+1)))
                return true;
        }
        
        cnt = 0;
        fill_n (vis, 256, 0);
        for (int i=0;i<len-1;i++){
            char a = s1[i], b = s2[len - 1 - i];
            if (vis[a] == 0)    cnt++;  vis[a]++;
            if (vis[a] == 0)    cnt--;
            if (vis[b] == 0)    cnt++;  vis[b]--;
            if (vis[b] == 0)    cnt--;
            if (cnt == 0 && isScramble(s1.substr(0,i+1), s2.substr(len-1-i)) && isScramble(s1.substr (i+1), s2.substr (0,len-i-1)))
                return true;
        }
        return false;
    }
};