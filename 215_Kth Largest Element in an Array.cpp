class Solution {
public:
    int dfs (vector<int>& nums, int l, int r, int k){
        int val = nums[l], idx = l;
        for (int i=l+1;i<=r;i++){
            if (nums[i] < val){
                swap (nums[i], nums[idx]);
                idx++;
                swap (nums[i], nums[idx]);
            }
        }
        nums[idx] = val;
        int left_num = idx - l;
        if (left_num == k - 1)  return val;
        else if (left_num >= k) return dfs (nums,l, idx-1,k);
        else                    return dfs (nums,idx+1,r,k-left_num-1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size ();
        return dfs (nums,0,sz-1,sz-k+1);
    }
};
