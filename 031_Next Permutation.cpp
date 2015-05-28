class Solution {
public:
    inline void reversed (vector<int>& nums, int s, int  e){
        while (s < e){
            swap (nums[s++], nums[e--]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size ();
        if (sz == 1)    return ;
        int idx = sz - 2;
        for (;idx>=0;idx--) if (nums[idx] < nums[idx+1])    break;
        if (idx == -1){
            reversed (nums,0,sz-1);
            return;
        }
        for (int i=sz-1;i>=idx+1;i--)   if (nums[i] > nums[idx]){
            swap (nums[idx], nums[i]);  break;
        }
        reversed (nums,idx+1, sz-1);
    }
};