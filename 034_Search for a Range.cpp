class Solution {
public:
    int find_ (vector<int>& nums, int sz, int target){
        int low = 0, high = sz-1, mid;
        while (low < high){
            mid = (low + high) >> 1;
            if (nums[mid] >= target)    high = mid;
            else        low = mid + 1;
        }
        return nums[low] >= target ? low : sz;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size ();
        vector<int> ans = {-1,-1};
        int start = find_ (nums, sz, target);
        if (start == sz)    return ans;
        if (nums[start] != target)  return ans;
        ans[0] = start;
        int end = find_ (nums, sz, target + 1);
        ans[1] = end - 1;
        return ans;
    }
};