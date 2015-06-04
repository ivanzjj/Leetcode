class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0,sz=nums.size();i<sz;i++)   res ^= nums[i];
        return res;
    }
};