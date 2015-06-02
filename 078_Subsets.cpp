class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void dfs (vector<int>& nums, int now, int n){
        if (now == n){
            ans.push_back (tmp);
            return;
        }
        dfs (nums,now + 1,n);
        tmp.push_back (nums[now]);
        dfs (nums,now + 1,n);
        tmp.pop_back ();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort (nums.begin (), nums.end());
        ans.clear (); tmp.clear ();
        dfs (nums, 0, nums.size ());
        return ans;
    }
};