class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void go (vector<int>& candidates, int i, int target){
        if (target == 0){
            ans.push_back (tmp);
            return;
        }
        if (i < 0)  return;
        if (candidates[i] > target)  return;
        int k = i, j;
        for (;k>=0 && candidates[k] == candidates[i];k--);
        go (candidates, k, target);
        
        for (j=i;j>k;j--){
            if (target >= candidates[j]){
                tmp.push_back (candidates[j]);
                go (candidates,k,target - candidates[j]);
            }
            else
                break;
            target -= candidates[j];
        }
        for (;j<i;j++)
            tmp.pop_back ();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end() );
        reverse (candidates.begin(), candidates.end ());
        ans.clear(); tmp.clear();
        go (candidates, candidates.size()-1, target);
        return ans;
    }
};