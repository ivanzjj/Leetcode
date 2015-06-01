class Solution {
public:
    string getPermutation(int n, int k) {
        string ans(n, '0');
        vector<bool> vis(n, false);
        vector<int> base(n,0);  base[0] = 1;
        for (int i=1;i<n;i++)   base[i] = i * base[i-1];
        
        for (int i=n-1,j;i>=0;i--){
            for (j=0;j<n;j++) if (!vis[j]){
                if (base[i] >= k)   break;
                else    k -= base[i];
            }
            ans[n - 1 - i] = '1' + j;
            vis[j] = 1;
        }
        return ans;
    }
};