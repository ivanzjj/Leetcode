class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for (int i=0,sz=nums.size();i<sz;i++){
            if (i == 0 || nums[i] != nums[i-1])  nums[cnt++] = nums[i];
        }
        nums.resize ( cnt );
        return cnt;
    }
};