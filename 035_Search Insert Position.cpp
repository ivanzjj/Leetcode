class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size () - 1, mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if (nums[mid] >= target)    high = mid;
            else        low = mid + 1;
        }
        return nums[low] >= target ? low : nums.size ();
    }
};