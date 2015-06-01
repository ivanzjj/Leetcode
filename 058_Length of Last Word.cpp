class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length (), i = len - 1, cnt = 0;
        while (i >= 0 && s[i] == ' ')   i--;
        if (i < 0)  return 0;
        while (i >= 0 && s[i] != ' ')   i--, cnt++;
        return cnt;
    }
};