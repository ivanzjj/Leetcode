class Solution {
public:
    int go (vector<int>& nums, int s, int e){
        if (s > e)  return 0;
        int a = 0, b = nums[s], c = nums[s];
        for (int i=s+1;i<=e;i++){
            c = max (b, a + nums[i]);
            a = b; b = c;
        }
        return c;
    }
    int rob(vector<int>& nums) {
        int N = nums.size ();
        if (N == 1) return nums[0];
        if (N == 2) return max(nums[0], nums[1]);
        if (N == 0) return 0;
        return max (nums[0] + go (nums,2, N-2), go (nums,1,N-1));
    }
};
