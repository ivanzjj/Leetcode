class Solution {
public:
    vector<string> ans;

    void dfs (int idx, int sz, string& s, int cc, string tmp){
        if (idx == sz){
            if (cc == 4)    ans.push_back (tmp);
            return;
        }
        if (cc == 4)    return;
        
        if (s[idx] == '0'){
            dfs (idx+1, sz, s, cc+1, cc==0?s.substr(idx,1):tmp+'.'+s.substr(idx,1));
            return;
        }
        int cnt = 0;
        for (int i=idx;i<sz;i++){
            cnt = cnt * 10 + s[i] - '0';
            if (cnt < 256){
                dfs (i+1, sz, s, cc+1, cc==0?s.substr(idx,i-idx+1):tmp+'.'+s.substr(idx,i-idx+1));
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int sz = s.length ();
        dfs (0, sz, s, 0, "");
        return ans;
    }
};