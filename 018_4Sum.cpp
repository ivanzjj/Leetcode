/*
O (N^3)
1 sort the array in non-descend order
2 enumerate the i and j, which is the smallest two element's index in quadruplets
3 then the problem become find x ,y, satisfy nums[x] + nums[y] = (target - nums[i] - nums[j])
  because i and j have been enumerated, so equation's right side is a constant value,
  the problem then become 2-sum problem. As you know, we can solve 2-sum problem using O(N)
  algorithm, so the time complexity is O(N^3).
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> ans;
        int sz = nums.size ();
        if (sz < 4)     return ans;
        sort (nums.begin (), nums.end());
        for (int i=0;i<sz;i++){
            if (i && nums[i] == nums[i-1])  continue;
            for (int j=i+1;j<sz;j++){
                if (j > i+1 && nums[j] == nums[j-1])    continue;
                int sum = target - nums[i] - nums[j];
                for (int low=j+1,high=sz-1;low < high; low++){
                    if (low > j+1 && nums[low] == nums[low-1])  continue;
                    while (low < high && nums[low] + nums[high] > sum)  high--;
                    if (low < high && nums[low] + nums[high] == sum){
                        ans.push_back ({nums[i], nums[j], nums[low], nums[high]});
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size ();
        vector <vector <int>> ans;
        if (sz < 4) return ans;
        sort (nums.begin(), nums.end());
        vector <pair<int, pair<int,int> > > vec;
        for (int i=0;i<sz;i++) {
            for (int j=i+1;j<sz;j++){
                if (j > i+1 && nums[j] == nums[j-1])    continue;
                vec.push_back ({nums[i] + nums[j], {i, j}});
            }
        }
        
        sort (vec.begin (), vec.end());
        sz = vec.size ();
        for (int low=0, high=sz-1; low<high ;low++){
            if (low && vec[low].first == vec[low-1].first && nums[vec[low].second.first] == nums[vec[low-1].second.first])  continue;
            while (low < high && vec[low].first + vec[high].first > target) high--;
            for (int now = high;low < now && vec[low].first + vec[now].first == target; now--){
                if (now < high && nums[vec[now].second.first]==nums[vec[now+1].second.first] )  continue;
                pair <int,int> &pa = vec[low].second, &pb = vec[now].second;
                if (pa.second < pb.first){
                    ans.push_back ({nums[pa.first],nums[pa.second],nums[pb.first],nums[pb.second]});
                }
            }
        }
        return ans;        
    }
};
