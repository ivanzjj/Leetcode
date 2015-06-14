class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int R = matrix.size ();
        if (!R) return 0;
        int C = matrix[0].size ();
        if (!C) return 0;
        stack<int> st;
        int *num = new int[C];
        int *dp = new int[C];
        fill_n (num, C, 0);
        int idx;
        int ans = 0;
        for (int r=0;r<R;r++){
            for (int c=0;c<C;c++){
                num[c] = matrix[r][c]=='1' ? num[c]+1 : 0;
            }
            fill_n (dp, C, 1);
            while (!st.empty ())    st.pop();
            for (int c=0;c<C;c++){
                while (!st.empty() && num[st.top()] >= num[c]){
                    idx = st.top ();
                    dp[idx] += c - idx - 1;
                    st.pop();
                }
                if (st.empty()) idx = -1;
                else            idx = st.top ();
                dp[c] += c - idx - 1;
                st.push (c);        
            }
            for (int c=0;c<C;c++){
                if (dp[c] >= num[c]){
                    ans = max (ans, num[c]);
                }
            }
        }
        return ans * ans;
    }
};

/*
Dynamic Programming
dp[i][j] mean the maximum square whose right down corner is (i,j)
then dp[i][j] = min (dp[i-1][j-1], min (dp[i-1][j], dp[i][j-1])) + 1
return MAX{dp[i][j]} ^ 2, for all i=0...R-1,j=0...C-1
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int R = matrix.size ();
        if (!R) return 0;
        int C = matrix[0].size ();
        if (!C) return 0;
        vector<int> dp[2] = {vector<int>(C, 0), vector<int>(C, 0)};
        int pre = 0, now = 1, ans = 0;
        for (int c=0;c<C;c++)   dp[now][c] = matrix[0][c] == '1', ans = max (ans, dp[now][c]);
        for (int i=1;i<R;i++){
            pre ^= 1; now ^= 1;
            fill_n (dp[now].begin(), C, 0);
            dp[now][0] = matrix[i][0] == '1';
            for (int j=1;j<C;j++) if (matrix[i][j] == '1'){
                dp[now][j] = min (dp[pre][j-1], min (dp[now][j-1], dp[pre][j])) + 1;
                ans = max (ans, dp[now][j]);
            }
            ans = max (ans, dp[now][0]);
        }
        return ans * ans;
    }
};