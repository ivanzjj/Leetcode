class Solution {
public:
    bool isPalindrome(string s) {
        int idx = 0, sz = s.length ();
        for (int i=0;i<sz;i++) if ((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            s[idx++] = (s[i]>='A' && s[i]<='Z' ? s[i]-'A'+'a' :s[i]);
        }
        sz = idx;
        if (sz == 0)    return true;
        int l = 0, r = sz - 1;
        while (l < r){
            if (s[l] != s[r])   return false;
            l++; r--;
        }
        return true;
    }
};