class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size ();
        vector <vector <int>> ans;
        if (sz < 3) return ans;
        
        sort (nums.begin (), nums.end ());
        for (int i=0;i<sz;i++){
            if (i && nums[i] == nums[i-1])  continue;
            int sum = -nums[i];
            for (int low=i+1,high=sz-1;low<high;low++){
                if (low > i+1 && nums[low] == nums[low - 1])    continue;
                while (low < high && nums[low] + nums[high] > sum)  high--;
                if (low < high && nums[low] + nums[high] == sum){
                    ans.push_back ({nums[i], nums[low], nums[high]});
                }
            }
        }
        return ans;
    }
};