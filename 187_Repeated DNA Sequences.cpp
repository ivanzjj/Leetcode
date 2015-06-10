class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sz = s.length ();
        vector<string> ans;
        if (sz < 10)    return ans;
        int state = 0;
        char ref[300]; ref['A'] = 0; ref['T'] = 1, ref['C'] = 2, ref['G'] = 3;
        for (int i=0;i<10;i++)  state = state << 2 | ref[ s[i] ];
        char num[1 << 20];
        memset (num, 0, sizeof(num));
        num[state] = 1;
        for (int i=10;i<sz;i++){
            state = (state & (~(3 << 18))) << 2 | ref[ s[i] ];
            if (num[state] == 0){
                num[state] = 1;
            }
            else if (num[state] == 1){
                ans.push_back (s.substr(i - 9, 10));
                num[state] = 2;
            }
        }
        return ans;
    }
};
