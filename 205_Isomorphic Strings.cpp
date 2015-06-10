class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char ref[300];
        bool vis[300];
        memset (ref, -1, sizeof(ref));
        fill_n (vis, 300, false);
        int len = s.length ();
        for (int i=0;i<len;i++){
            if (ref[ s[i] ] == -1){
                // not yet;
                if ( vis[ t[i] ] )  return false;
                ref[ s[i] ] = t[i];
                vis[ t[i] ] = true;
            }
            else if (ref[ s[i] ] != t[i])   return false;
        }
        return true;
    }
};
