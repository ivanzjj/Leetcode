class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        int sz = s.length ();
        vector <string> vec (numRows, "");
        for (int i=0,idx=0,flag=-1;i<sz;i++){
            vec[idx] += s[i];
            if (idx == 0 || idx == numRows-1) flag *= (-1);
            idx += flag;
        }
        string ans;
        for (int i=0;i<numRows;i++) ans += vec[i];
        return ans;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        int sz = s.length ();
        string ans = "";
        for (int i = 0; i < min (sz, numRows); i++){
            int flag = 1, new_idx;
            ans += s[i];
            for (int idx = i; idx < sz; ){
                new_idx = idx + flag * (2*numRows-2*i-2) + (1 - flag)*(2*i);
                if (idx != new_idx && new_idx < sz){
                    ans += s[new_idx];
                }
                idx = new_idx; flag ^= 1;
            }
        }
        return ans;
    }
};