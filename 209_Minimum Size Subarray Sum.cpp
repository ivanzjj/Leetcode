class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int ans = nums.size () + 1;
        for (int i=0,sz=nums.size(),j=0;i<sz;i++){
            while (j<sz && sum+nums[j] < s) sum += nums[j], j++;
            if (j == sz)    break;
            ans = min (ans, j-i+1);
            sum = sum - nums[i];
        }
        if (ans == nums.size () + 1)    ans = 0;
        return ans;
    }
};
