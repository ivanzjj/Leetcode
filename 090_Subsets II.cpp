class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> flag;
    vector<int> tmp;
    
    void dfs (vector<int>& nums, int now, int n){
        if (now == n){
            tmp.clear ();
            for (int i=0;i<n;i++)   if (flag[i])    tmp.push_back (nums[i]);
            ans.push_back (tmp);
            return;
        }
        dfs (nums, now + 1, n);
        if (now==0 || nums[now] != nums[now-1] || flag[now-1]){
            flag[now] = 1;
            dfs (nums, now+1, n);
            flag[now] = 0;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear (); tmp.clear ();
        int sz = nums.size ();
        sort (nums.begin(), nums.end());
        flag.resize (sz);
        fill_n (flag.begin(), sz, false);
        dfs (nums,0,sz);
        return ans;
    }
};