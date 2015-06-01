class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length (), lb = b.length (), c = 0, idx;
        idx = max(la, lb) + 1;
        string ans (idx, '0');
        int i = la - 1, j = lb - 1;
        int x, y, z; idx--;
        while (i >= 0 || j >= 0 || c){
            x = y = 0;
            if (i >= 0) x = a[i] - '0', i--;
            if (j >= 0) y = b[j] - '0', j--;
            z = x + y + c;
            c = z / 2; z %= 2;
            ans[idx--] = z + '0';
        }
        return ans.substr (idx+1);
    }
};