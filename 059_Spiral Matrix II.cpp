class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        int up = 0, down = n-1, left = 0, right = n-1, now = 1;
        while (up <= down && left <= right){
            for (int j=left;j<=right;j++)   ans[up][j] = now++;
            for (int i=up+1;i<=down;i++)    ans[i][right] = now++;
            if (up == down) break;
            for (int j=right-1;j>=left;j--) ans[down][j] = now++;
            if (left == right)  break;
            for (int i=down-1;i>up;i--)     ans[i][left] = now++;
            up++; down--; left++; right--;
        }
        return ans;
    }
};