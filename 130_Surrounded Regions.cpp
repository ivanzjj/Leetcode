class Solution {
public:
    int R, C;
    int dr[4] = {-1,0,0,1};
    int dc[4] = {0,-1,1,0};
    
    void solve(vector<vector<char>>& board) {
        R = board.size ();
        if (!R) return;
        C = board[0].size ();
        if (!C) return;
        
        queue<pair<int,int>> que;
        int r,c,nr,nc;
        
        for (int i=0;i<R;i++){
            if (board[i][0] == 'O'){
                board[i][0] = 'G';
                que.push ({i,0});
                while (!que.empty ()){
                    r = que.front().first, c = que.front().second; que.pop();
                    for (int i=0;i<4;i++){
                        nr = r + dr[i];
                        nc = c + dc[i];
                        if (nr >= 0 && nr<R && nc>=0 && nc<C && board[nr][nc] == 'O'){
                            board[nr][nc] = 'G';
                            que.push ({nr,nc});
                        }
                    }
                }
            }
            if (board[i][C-1] == 'O'){
                board[i][C-1] = 'G';
                que.push ({i,C-1});
                while (!que.empty ()){
                    r = que.front().first, c = que.front().second; que.pop();
                    for (int i=0;i<4;i++){
                        nr = r + dr[i];
                        nc = c + dc[i];
                        if (nr >= 0 && nr<R && nc>=0 && nc<C && board[nr][nc] == 'O'){
                            board[nr][nc] = 'G';
                            que.push ({nr,nc});
                        }
                    }
                }
            }
        }
        for (int j=1;j<C-1;j++){
            if (board[0][j] == 'O'){
                board[0][j] = 'G';
                que.push ({0,j});
                while (!que.empty ()){
                    r = que.front().first, c = que.front().second; que.pop();
                    for (int i=0;i<4;i++){
                        nr = r + dr[i];
                        nc = c + dc[i];
                        if (nr >= 0 && nr<R && nc>=0 && nc<C && board[nr][nc] == 'O'){
                            board[nr][nc] = 'G';
                            que.push ({nr,nc});
                        }
                    }
                }
            }
            if (board[R-1][j] == 'O'){
                board[R-1][j] = 'G';
                que.push ({R-1,j});
                while (!que.empty ()){
                    r = que.front().first, c = que.front().second; que.pop();
                    for (int i=0;i<4;i++){
                        nr = r + dr[i];
                        nc = c + dc[i];
                        if (nr >= 0 && nr<R && nc>=0 && nc<C && board[nr][nc] == 'O'){
                            board[nr][nc] = 'G';
                            que.push ({nr,nc});
                        }
                    }
                }
            }
        }
        for (int i=0;i<R;i++) for (int j=0;j<C;j++){
            if (board[i][j] == 'G') board[i][j] = 'O';
            else if (board[i][j] == 'O')    board[i][j] = 'X';
        }
    }
};