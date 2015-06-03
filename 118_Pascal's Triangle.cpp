class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0)   return ans;
        ans.push_back (vector<int>(1,1));
        int sz = 1;
        for (int i=2;i<=numRows;i++){
            ans.push_back (ans[i-2]);
            for (int j=sz-1;j>0;j--)    ans[i-1][j] += ans[i-1][j-1];
            ans[i-1].push_back (1); sz++;
        }
        return ans;
    }
};