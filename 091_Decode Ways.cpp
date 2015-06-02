class Solution {
public:
    int numDecodings(string s) {
        int sz = s.length ();
        if (sz == 0)    return 0;
        int a,b,c,tmp;
        b = 1; c = -1;
        for (int i=sz-1;i>=0;i--){
            a = 0;
            if (i + 1 < sz && s[i] != '0'){
                tmp = (s[i] - '0') * 10 + s[i + 1] - '0';
                if (tmp <= 26)  a += c;
            }
            tmp = (s[i] - '0');
            if (tmp >= 1 && tmp < 10)   a += b;
            c = b;
            b = a;
        }
        return a;
    }
};