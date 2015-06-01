class Solution {
public:
    bool canJump(vector<int>& nums) {
        int low = 0, high = 1, sz = nums.size ();
        while (low < high && low < sz){
            if (nums[low] + low + 1 > high) high = nums[low] + low + 1;
            low++;
        }
        return high >= sz;
    }
};