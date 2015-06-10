class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size ();
        int a = nums[0], cnt = 1;
        for (int i=1;i<sz;i++){
            if (a == nums[i])   cnt++;
            else{
                if (cnt == 0)   a = nums[i], cnt = 1;
                else        cnt--;
            }
        }
        return a;
    }
};
