/*
dynamic programming.

first we can proof: if x < y, then dp[x] <= dp[y]
so for every i, we just need update dp[i] with smallest x,
which satisfy x + nums[x] >= i
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size ();
        int *dp = new int[sz];
        for (int i=0;i<sz;i++)  dp[i] = sz + 1;
        dp[0] = 0;
        for (int i=1,now=0;i<sz;i++){
            if (now + nums[now] >= i)   dp[i] = dp[now] + 1;
            else{
                while (now<i && now + nums[now] < i) now++;
                if (now == i)   return -1;
                dp[i] = dp[now] + 1;
            }
        }
        return dp[sz - 1];
    }
};