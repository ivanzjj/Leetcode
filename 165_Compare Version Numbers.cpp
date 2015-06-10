class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, len1 = version1.length (), len2 = version2.length ();
        while (i<len1 || j<len2){
            int a = 0, b = 0;
            int ii = i, jj = j;
            while (ii<len1 && version1[ii]>='0' && version1[ii]<='9')   a = a * 10 + version1[ii] - '0', ii++;
            while (jj<len2 && version2[jj]>='0' && version2[jj]<='9')   b = b * 10 + version2[jj] - '0', jj++;
            if (a < b)  return -1;
            else if (a > b) return 1;
            i = ii + 1; j = jj + 1;
        }
        return 0;
    }
};
