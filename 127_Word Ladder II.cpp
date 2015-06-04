class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> pre;
    vector<string> tmp;
    string _begin;
    
    void dfs (string now){
        if (now == _begin){
            ans.push_back (vector<string>());
            for (int i=0,sz=tmp.size();i<sz;i++){
                ans.back ().push_back (tmp[sz - 1 - i]);
            }
            return;
        }
        if (pre.count (now) == 0)   return;
        for (int i=0;i<pre[now].size();i++){
            tmp.push_back (pre[now][i]);
            dfs (pre[now][i]);
            tmp.pop_back ();
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        queue <string> que;
        unordered_map<string, int> mp;
        que.push (start); mp[start] = 1;
        int len = start.length ();
        pre.clear ();
        int _min = INT_MAX;
        
        while (!que.empty()){
            string now = que.front (); que.pop();
            int cnt = mp[now];
            if (cnt >= _min)    break;
            string tmp = now;
            for (int i=0;i<len;i++){
                for (int j=0;j<26;j++){
                    tmp[i]++; if (tmp[i] > 'z') tmp[i] -= 26;
                    if (dict.find(tmp) == dict.end())   continue;
                    if (tmp == end)     _min = min (_min, cnt + 1);
                    if (mp.count (tmp) == 0){
                        mp[tmp] = cnt + 1;
                        pre[tmp] = vector<string>();
                        pre[tmp].push_back (now);
                        que.push (tmp);
                    }
                    else if (mp[tmp]==cnt+1){
                        pre[tmp].push_back (now);
                    }
                }
            }
        }
        ans.clear ();
        if (_min == INT_MAX)    return ans;
        tmp.push_back (end); _begin = start;
        dfs (end);
        return ans;
    }
};