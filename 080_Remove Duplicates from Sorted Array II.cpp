class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, sz = nums.size ();
        if (sz == 0)    return 0;
        int count = 1, tmp;
        for (int i=1;i<sz;i++){
            tmp = nums[i - 1];      // nums[i-1] maybe changed by nums[idx++] = nums[i], so store it first
            if ((nums[i] != nums[i-1]) || (count == 1)){
                nums[idx++] = nums[i];                
            }
            count = (nums[i] == tmp ? 2: 1);
        }
        return idx;
    }
};