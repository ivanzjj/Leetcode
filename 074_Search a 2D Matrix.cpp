class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size ();
        if (!R) return false;
        int C = matrix[0].size ();
        if (!C) return false;
        int low_r = 0, high_r = R - 1, mid_r;
        while (low_r < high_r){
            mid_r = (low_r + high_r + 1) >> 1;
            if (target < matrix[mid_r][0])  high_r = mid_r - 1;
            else        low_r = mid_r;
        }
        if (matrix[low_r][0] > target)  return false;
        int low_c = 0, high_c = C - 1, mid_c;
        while (low_c < high_c){
            mid_c = (low_c + high_c + 1) >> 1;
            if (matrix[low_r][mid_c] <= target) low_c = mid_c;
            else        high_c = mid_c - 1;
        }
        return matrix[low_r][low_c] == target;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size ();
        if (!R) return false;
        int C = matrix[0].size ();
        if (!C) return false;
        int low = 0, high = R*C-1, mid;
        while (low < high){
            mid = (low + high + 1) >> 1;
            if (matrix[mid/C][mid%C] <= target) low = mid;
            else        high = mid - 1;
        }
        return matrix[low/C][low%C] == target;
    }
};