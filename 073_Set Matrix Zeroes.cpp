class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size ();
        if (!R) return;
        int C = matrix[0].size ();
        if (!C) return;
        
        bool row0 = false, col0 = false;
        for (int j=0;j<C;j++)   row0 = row0 || (matrix[0][j] == 0);
        for (int i=0;i<R;i++)   col0 = col0 || (matrix[i][0] == 0);
        for (int i=1;i<R;i++) for (int j=1;j<C;j++) if (matrix[i][j] == 0){
            matrix[0][j] = matrix[i][0] = 0;
        }
        for (int i=1;i<R;i++){
            if (matrix[i][0] == 0)
                for (int j=1;j<C;j++)   matrix[i][j] = 0;
        }
        for (int j=1;j<C;j++){
            if (matrix[0][j] == 0)
                for (int i=1;i<R;i++)   matrix[i][j] = 0;
        }
        if (row0)   for (int j=0;j<C;j++)   matrix[0][j] = 0;
        if (col0)   for (int i=0;i<R;i++)   matrix[i][0] = 0;
    }
};