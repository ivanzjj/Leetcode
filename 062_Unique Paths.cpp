class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 1;
        if (m < n)  swap (n,m);
        for (int i=1;i<=n-1;i++)  res = res * (long long)(m + n - 1 - i) / i ;
        return res;
    }
};