/*
 KMP
 */
class Solution {
public:
    vector<int> nxt;
    
    void _get (string& s,int len){
        nxt[0] = -1;
        int j = -1;
        for (int i=1;i<len;i++){
            while (j!=-1 && s[i]!=s[j+1]) j = nxt[j];
            if (s[i] == s[j+1]) j++;
            nxt[i] = j;
        }
    }
    string shortestPalindrome(string s) {
        int len = s.length ();
        if (len < 2)    return s;
        nxt.resize (len);
        _get (s, len);
        int j = -1;
        string tmp = s;
        reverse (tmp.begin(), tmp.end());
        for (int i=0;i<len;i++){
            while (j!=-1 && tmp[i]!=s[j+1])   j = nxt[j];
            if (tmp[i] == s[j+1])   j++;
        }
        return tmp.substr (0,len-j-1) + s;        
    }
};




class Solution {
public:
    string shortestPalindrome(string s) {
        string tmp = s + s + '#';
        int len = s.length ();
        if (len < 2)    return s;
        for (int i=0;i<len;i++) tmp[i<<1] = '#', tmp[i<<1|1] = s[i];
        vector<int> p (len<<1|1, 1);
        int idx = 0, mx = 1;
        int _idx = 0, _max = 1;
        
        for (int i=1;i<len*2+1;i++){
            if (i < mx){
                p[i] = min (p[2*idx-i], mx - i);
            }
            else 
                p[i] = 1;
            int l = i - p[i], r = i + p[i];
            while (l>=0 && r<len*2+1 && tmp[l] == tmp[r])   l--, r++;
            p[i] = r - i;
            if (r > mx){
                mx = r; idx = i;
            }
            if (l == -1){
                _max = r;
            }
        }
        int left = len - (_max >> 1);
        string ss = s.substr (_max>>1, left);
        reverse (ss.begin(), ss.end());
        return ss + s;
    }
};
