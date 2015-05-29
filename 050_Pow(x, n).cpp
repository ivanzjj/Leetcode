/*
be careful with n < 0 and n = INT_MIN
*/
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long nn = n;
        if (nn < 0) x = 1 / x, nn = -nn;
        while (nn){
            if (nn & 1)  res *= x;
            x *= x; nn >>= 1;
        }
        return res;
    }
};