class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length (), tlen = t.length ();
        int tt[300] = {0};
        for (int i=0;i<tlen;i++)    tt[ t[i] ]++;
        int tmp[300] = {0};
        int cnt = 0;
        
        int _min = slen + 1;
        string ans = "";
        for (int i=0,j=0;i<slen;i++){
            while (j<slen && cnt < tlen){
                if ( tmp[s[j]] < tt[s[j]])  cnt++;
                tmp[ s[j] ]++; j++;
            }
            if (cnt == tlen && _min > j - i){
                _min = j - i;
                ans = s.substr (i, _min);
            }
            if (j > i){
                if (tmp[s[i]] <= tt[s[i]])  cnt--;
                tmp[s[i]]--;
            }
            else    j = i + 1;
        }
        return ans;
    }
};