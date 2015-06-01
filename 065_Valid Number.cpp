class Solution {
public:
    bool isNumber(string s) {
        int sz = s.length (),i = 0;
        int j = 0;
        for (;j<sz;j++) if (s[j] != ' ')    break;
        for (;j<sz;j++) s[i++] = s[j];
        i--;
        while (i >= 0 && s[i] == ' ')   i--;
        sz = i + 1;
        if (sz == 0)    return false;
        if (s[0] == '+' || s[0] == '-') i = 1;
        else            i = 0 ;
        
        int dfn[10][300];
        memset (dfn, 0, sizeof(dfn));
        for (int i=0;i<10;i++)  dfn[1][i+'0'] = 2, dfn[2][i + '0'] = 2, dfn[7][i + '0'] = 7, dfn[3][i + '0'] = 4, dfn[4][i + '0'] = 4, dfn[5][i + '0'] = 8, dfn[6][i + '0'] = 8, dfn[8][i + '0'] = 8;
        dfn[1]['.'] = 3;
        dfn[2]['.'] = 7;
        dfn[2]['e'] = dfn[2]['E'] = dfn[4]['e'] = dfn[4]['E'] = 5;
        dfn[7]['e'] = dfn[7]['E'] = 5;
        dfn[5]['+'] = 6; dfn[5]['-'] = 6;
    
        int now = 1;
        for (;i<sz;i++){
            if (s[i] == ' ')    return false;
            if (dfn[now][ s[i] ] == 0)    return false;
            now = dfn[now][ s[i] ];
        }
        return now != 3 && now != 5 && now != 6;
    }
};