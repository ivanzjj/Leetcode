class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length (), idx = 0, pos = 0;
        while (len && s[len-1] == ' ')  len--;
        while (idx<len && s[idx] == ' ')    idx++;
        for (int i=idx;i<len;i++){
            if (s[i]==' ' && (i>idx&&s[i-1]==' '))  continue;
            s[pos++] = s[i];
        }
        len = pos;
        s.resize (len);
        for (int i=0;i*2<len;i++){
            swap (s[i], s[len-1-i]);
        }
        for (int ss=0,ee;ss<len;ss=ee+1){
            ee = ss;
            while (ee<len && s[ee] != ' ')    ee++;
            int len2 = ee - ss;
            for (int j=0;j*2<len2;j++){
                swap (s[ss+j], s[ee-1-j]);
            }
        }
    }
};
