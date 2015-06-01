class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        if (nums.size () == 0)  return INT_MIN;
        int high = 0, sum = 0;
        for (int i=0,sz=nums.size();i<sz;i++){
            if (i == high)  sum = nums[i], high++;
            ans = max (ans, sum);
            if (nums[i] > 0){
                while (high < sz && sum + nums[high] > 0){
                    sum += nums[high++];
                    ans = max (ans, sum);
                }
            }
            sum -= nums[i];
        }
        return ans;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size ();
        if (sz == 0)    return INT_MIN;
        int ans = nums[0], sum = 0;
        for (int i=0;i<sz;i++){
            sum += nums[i];
            ans = max (ans, sum);
            if (sum < 0)    sum = 0;
        }
        return ans;
    }
};