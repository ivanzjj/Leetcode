class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back (1); 
        int sz = 1;
        for (int i=1;i<=rowIndex;i++){
            for (int i=sz-1;i>0;i--)    ans[i] += ans[i - 1];
            ans.push_back (1); sz++;
        }
        return ans;
    }
};