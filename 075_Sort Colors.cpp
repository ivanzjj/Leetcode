class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num[3] = {0};
        for (int i=0,sz=nums.size();i<sz;i++){
            num[ nums[i] ]++;
        }
        int i=0;
        while (i < num[0])  nums[i] = 0, i++;
        while (i < num[0] + num[1]) nums[i] = 1, i++;
        while (i < num[0] + num[1] + num[2])    nums[i] = 2, i++;
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size ();
        int low = 0, high = sz - 1, p0 = 0, p2 = sz-1;
        while (low <= p2){
            if (nums[low] == 0){
                nums[p0] = nums[low];
                if (low > p0)   nums[low] = 1;
                p0++; low++;
            }
            else if (nums[low] == 1)    low++;
            else{
                while (low < p2 && nums[p2] == 2)   p2--;
                swap (nums[low], nums[p2]); p2--;
            }
        }
        return;
    }
};