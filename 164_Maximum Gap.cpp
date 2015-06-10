class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int sz = nums.size ();
        if (sz < 2) return 0;
        if (sz == 2)    return max(nums[0],nums[1]) - min(nums[0], nums[1]);
        
        int _min = INT_MAX, _max = INT_MIN;
        for (int i=0;i<sz;i++) _min = min (_min, nums[i]), _max = max(_max, nums[i]);
        int tot = _max - _min + 1;
        int bar, cap;
        if (tot < sz)   cap = 1, bar = tot;
        else            cap = (tot + sz - 1) / sz, bar = sz;
        
        int *num = new int[bar];
        int *ele_min = new int[bar];
        int *ele_max = new int[bar];
        fill_n (num, bar, 0);
        fill_n (ele_min, bar, INT_MAX);
        fill_n (ele_max, bar, INT_MIN);
        
        for (int i=0;i<sz;i++){
            int idx = (nums[i] - _min) / cap;
            num[idx]++;
            ele_min[idx] = min (ele_min[idx], nums[i]);
            ele_max[idx] = max (ele_max[idx], nums[i]);
        }
        int ans = 0;
        
        for (int i=0;i<bar-1;i++){
            if (num[i] == 0){
                int j = i + 1;
                while (j<bar && num[j]==0)   j++;
                ans = max (ans, ele_min[j] - ele_max[i-1]);
                i = j;
            }
            else if (num[i]==1 && num[i+1]==1){
                ans = max (ans, ele_min[i+1] - ele_min[i]);
            }
        }
        return ans;
    }
};
