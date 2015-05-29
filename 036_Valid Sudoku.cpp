class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis[10] = {0}, visn = 0, t;
        vector <vector <int>> maze(9, vector<int>(9,-1));
        for (int i=0;i<9;i++)   for (int j=0;j<9;j++) if (board[i][j] != '.')
            maze[i][j] = board[i][j] - '0';
            
        for (int i=0;i<9;i++){
            visn++;
            for (int j=0;j<9;j++)   if ((t=maze[i][j]) != -1){
                if (vis[t] == visn) return false;
                vis[t] = visn;
            }
        }
        for (int i=0;i<9;i++){
            visn++;
            for (int j=0;j<9;j++) if ((t=maze[j][i]) != -1){
                if (vis[t] == visn)   return false;
                vis[t] = visn;
            }
        }
        for (int i=0;i<9;i++) for (int j=0;j<9;j++) if (i%3==0 && j%3==0){
            visn++;
            for (int ii=0;ii<3;ii++)    for (int jj=0;jj<3;jj++) if ((t = maze[i+ii][j+jj]) != -1){
                if (vis[t] == visn)   return false;
                vis[t] = visn;
            }
        }
        return true;
    }
};