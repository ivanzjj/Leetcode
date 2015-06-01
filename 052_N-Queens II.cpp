class Solution {
public:
    int ans;
    void dfs (int n, int i, int a, int b, int c){
        if (i == n){
            ans++; return;
        }
        int st = a >> 1 | b | c << 1, now;
        
        for (int j=0;j<n;j++) if (!(st >> j & 1)){
            now = 1 << j;
            dfs (n, i+1, a>>1|now,b|now,c<<1|now);
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        dfs (n, 0, 0, 0, 0);
        return ans;
    }
};