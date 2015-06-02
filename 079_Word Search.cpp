class Solution {
public:
    vector<vector<int>> vis;
    int R, C;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    
    bool dfs (int r, int c, int idx, vector<vector<char>>& board, string& word, int len){
        if (idx == len - 1) return true;
        int nr, nc;
        for (int i=0;i<4;i++){
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr>=0 && nr<R && nc>=0 && nc<C && !vis[nr][nc] && board[nr][nc] == word[idx+1]){
                vis[nr][nc] = 1;
                if (dfs (nr,nc,idx+1,board,word,len))   return true;
                vis[nr][nc] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return true;
        R = board.size ();
        if (!R)     return false;
        C = board[0].size ();
        if (!C)     return false;
        vis.resize (R);
        for (int i=0;i<R;i++)  vis[i].resize (C), fill_n (vis[i].begin(), C, 0);
        
        for (int i=0;i<R;i++) for (int j=0;j<C;j++) if (word[0] == board[i][j]){
            vis[i][j] = 1;
            if (dfs(i,j,0,board, word, word.length())) return true;
            vis[i][j] = 0;
        }
        return false;
    }
};