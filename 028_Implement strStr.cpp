class Solution {
public:
    int strStr(string a, string b) {
        int len1 = a.length (), len2 = b.length ();
        if (len1 < len2)    return -1;
        if (len2 == 0)      return 0;
        
        vector <int> next (len2, -1);
        next[0] = -1;
        int j = -1;
        for (int i=1;i<len2;i++){
            while (j != -1 && b[i] != b[j+1])   j = next[j];
            if (b[i] == b[j+1]) j++;
            next[i] = j;
        }
        j = -1;
        for (int i=0;i<len1;i++){
            while (j != -1 && a[i] != b[j+1])   j = next[j];
            if (a[i] == b[j+1]) j++;
            if (j == len2-1)    return i - len2 + 1;
        }
        return -1;
    }
};