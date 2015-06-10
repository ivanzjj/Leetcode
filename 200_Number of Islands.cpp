class Solution {
public:
    typedef pair<int, int> PP;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size ();
        if (!R) return 0;
        int C = grid[0].size ();
        if (!C) return 0;
        int ans = 0;
        queue <PP> que;
        
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++) if (grid[i][j] == '1'){
                ans ++;
                que.push ({i,j});
                grid[i][j] = '2';
                while (!que.empty()){
                    int r = que.front().first;
                    int c = que.front().second;
                    que.pop();
                    for (int i=0;i<4;i++){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if (nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc]=='1'){
                            grid[nr][nc] = '2';
                            que.push ({nr,nc});
                        }
                    }
                }
            }
        }
        for (int i=0;i<R;i++)for (int j=0;j<C;j++)   if (grid[i][j] == '2') grid[i][j] = '1';
        return ans;
    }
};
