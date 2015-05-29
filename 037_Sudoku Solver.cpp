class Solution {
public:
    bool er[9][9], ec[9][9], eb[3][3][9];
    
    bool is_ok (int r, int c, int val){
        if (val == 0)   return false;   val--;
        if (er[r][val] || ec[c][val] || eb[r/3][c/3][val])  return false;
        er[r][val] = ec[c][val] = eb[r/3][c/3][val] = true;
        return true;
    }
    
    bool dfs (vector <vector<char> >& maze, int r, int c){
        if (c == 9) return dfs (maze, r+1, 0);
        if (r == 9) return true;
        if (maze[r][c] != '.')  return dfs (maze, r,c +1);
        
        for (int i=1;i<=9;i++){
            if (is_ok (r,c,i)){
                maze[r][c] = i + '0';
                if (dfs (maze, r,c+1))  return true;
                er[r][i-1] = ec[c][i-1] = eb[r/3][c/3][i-1] = false;
            }
        }
        maze[r][c] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset (er, 0, sizeof(er));
        memset (ec, 0, sizeof(ec));
        memset (eb, 0, sizeof(eb));
        for (int i=0;i<9;i++)  for (int j=0;j<9;j++) if (board[i][j] != '.'){
            int t = board[i][j] - '1';
            er[i][t] = ec[j][t] = eb[i/3][j/3][t] = true;
        }
        dfs (board, 0, 0);
    }
};