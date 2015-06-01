class Solution {
public:
    vector<string> vec;
    vector<string> mid_res;
    vector<vector<string>> ans;
    
    void dfs (int n, int i, int a, int b, int c){
        if (i == n){
            ans.push_back (mid_res);
            return;
        }
        int d = (a >> 1) | b | (c << 1), cc;
        for (int j=0;j<n;j++) if(!(d >> j & 1)){
            mid_res.push_back (vec[j]);
            cc = (1 << j);
            dfs (n, i+1, a >> 1 | cc, b | cc ,c << 1 | cc);
            mid_res.pop_back ();
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vec.resize (n);
        string tmp (n, '.');
        fill (vec.begin (), vec.end(), tmp);
        ans.clear(); mid_res.clear();
        for (int i=0;i<n;i++)   vec[i][i] = 'Q';
        dfs (n,0,0,0,0);
        return ans;
    } 
};