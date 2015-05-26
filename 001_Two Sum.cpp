class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        int sz = nums.size ();
        vector <pair<int,int> > mid;
        for (int i = 0; i < sz; i++)    mid.push_back ({nums[i], i});
        sort (mid.begin(), mid.end());
        for (int low=0,high=sz-1;low<high;high--){
            while (low < high && mid[low].first + mid[high].first < target)   low++;
            if (low < high && mid[low].first+mid[high].first==target){
                ans.push_back (mid[low].second + 1); ans.push_back(mid[high].second + 1);
                if (ans[0] > ans[1])    swap (ans[1], ans[0]);
                return ans;
            }
        }
        return ans;
    }
};