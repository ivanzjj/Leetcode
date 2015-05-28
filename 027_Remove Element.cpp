class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (int i=0,sz=nums.size();i<sz;i++){
            if (nums[i] != val) nums[cnt++] = nums[i];
        }
        nums.resize (cnt);
        return cnt;
    }
};