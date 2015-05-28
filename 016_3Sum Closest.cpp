class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size ();
        sort (nums.begin (), nums.end() );
        int min_diff = 100000000, res;
        
        for (int i=0;i<sz;i++){
            if (i && nums[i] == nums[i-1])  continue;
            for (int low=i+1,high=sz-1,t;low<high;low++){
                if (low>i+1 && nums[low]==nums[low-1])  continue;
                while (low < high && (t=nums[i]+nums[low]+nums[high]) > target) high --;
                if (low < high){
                    if (min_diff > target - t){
                        min_diff = target - t; res = t;
                    }
                }
                if (high+1<sz && (t=nums[i]+nums[low]+nums[high+1]) > target && min_diff > t-target){
                    min_diff = t - target;  res = t;
                }
            }
        }
        return res;
    }
};