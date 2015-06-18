class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs (int k,int nk,int now, int left){
        if (nk == k){
            if (left == 0)  ans.push_back (tmp);
            return;
        }
        if (now == 10)  return;
        if (left == 0)  return;
        
        dfs (k,nk,now+1,left);
        if (left >= now){
            tmp.push_back (now);
            dfs (k,nk+1,now+1,left-now);
            tmp.pop_back ();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear (); tmp.clear ();
        dfs (k,0,1,n);
        return ans;
    }
};
