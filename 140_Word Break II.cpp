class Solution {
public:
    vector<string> ans;
    vector<bool> dp;
    int slen;
    typedef pair<string,int> PP;
    vector<vector<int>> pos;
    
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        slen = s.length ();
        dp.resize (slen + 1);
        fill_n (dp.begin(), slen+1, false);
        dp[slen] = true;
        pos.resize (slen+1);
        fill_n (pos.begin(), slen+1,vector<int>());
        
        for (int i=slen;i>0;i--) if(dp[i]){
            for (int j=1;i-j>=0;j++){
                if (dict.find (s.substr(i-j,j)) != dict.end())  dp[i-j] = true, pos[i - j].push_back (i);
            }
        }
        ans.clear ();
        if (dp[0] == false)     return ans;
        
        queue<PP> que[2];
        int pre = 0, now = 1;
        for (int i=0;i<pos[0].size ();i++){
            que[now].push ({s.substr(0,pos[0][i]),pos[0][i]});
        }
        
        while (!que[now].empty()){
            pre ^= 1; now ^= 1;
            while (!que[pre].empty ()){
                string tmp = que[pre].front().first;
                int st = que[pre].front().second; que[pre].pop();
                if (st == slen){
                    ans.push_back (tmp);
                    continue;
                }
                for (int j=0;j<pos[st].size();j++){
                    que[now].push ({tmp + " " + s.substr(st,pos[st][j] - st), pos[st][j]});
                }
            }
        }
        return ans;
    }
};