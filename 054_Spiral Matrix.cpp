class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int R = matrix.size ();
        if (R == 0) return ans;
        int C = matrix[0].size ();
        int up = 0, down = R - 1, left = 0, right = C - 1;
        while (up <= down && left <= right){
            for (int i=left;i<=right;i++)   ans.push_back (matrix[up][i]);
            for (int i=up+1;i<=down;i++)    ans.push_back (matrix[i][right]);
            if (up == down) break;
            for (int i=right-1;i>=left;i--) ans.push_back (matrix[down][i]);
            if (left == right)  break;
            for (int i=down-1;i>up;i--)     ans.push_back (matrix[i][left]);
            up++; down--; left++; right--;
        }
        return ans;        
    }
};