class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int a, b, c;
        a = 1, b = 1;
        for (int i=1;i<n;i++){
            c = (a + b);
            a = b; b = c;
        }
        return c;
    }
};