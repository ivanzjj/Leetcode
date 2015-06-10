class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size ();
        if (sz == 0)    return 0;
        if (sz == 1)    return nums[0];
        if (sz == 2)    return max (nums[0], nums[1]);
        int a,b,c;
        a = nums[0]; b = max (nums[0], nums[1]);
        for (int i=2;i<sz;i++){
            c = max (b, a+nums[i]);
            a = b; b = c;
        }
        return c;
    }
};
