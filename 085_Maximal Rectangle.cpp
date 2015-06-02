class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int R = matrix.size ();
        if (!R) return 0;
        int C = matrix[0].size ();
        if (!C) return 0;
        int *num = new int[C];
        fill_n (num, C, 0);
        int *dp = new int[C];
        int ans = 0;
        int *st = new int[C];
        int top = 0;
        
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++)
                num[j] = matrix[i][j] == '1' ? num[j] + 1 :0;
            top = 0;
            fill_n (dp, C, 1);
            
            for (int j=0;j<C;j++){
                while (top && num[st[top-1]] >= num[j]){
                    dp[st[top-1]] += j - 1 - st[top-1]; top--;
                } 
                int idx = top==0 ? 0 : st[top-1] + 1;
                dp[j] += j - idx;
                st[top++] = j;
            }
            while (top) dp[st[top-1]] += (C - 1 - st[top-1]) , top--;
            for (int j=0;j<C;j++)   ans = max (ans, dp[j] * num[j]);
        }
        return ans;
    }
};