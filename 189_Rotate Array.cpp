class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size ();
        k %= n;
        if (k == 0) return;
        for (int l=0,r=(n-k-1);l<r;l++,r--)
            swap (nums[l], nums[r]);
        for (int l=n-k,r=n-1;l<r;l++,r--)
            swap (nums[l], nums[r]);
        for (int l=0,r=n-1;l<r;l++,r--)
            swap (nums[l], nums[r]);
    }
};
