class Solution {
public:
    bool is_ok (long long a, long long b, long long c){
        long long res = 0;
        while (c){
            if (c & 1)  res += b;
            if (res > a)    return false;
            c >>= 1; b <<= 1;
        }
        return true;
    }
    int divide(int a, int b) {
        int sgn = 1;
        long long aa = a, bb = b;
        if ((a>0&&b<0) || (a<0&&b>0))   sgn = -1;
        aa = (aa > 0 ? aa : -aa );
        bb = (bb > 0 ? bb : -bb );
        if (aa < bb)    return 0;
        long long low = 1, high = INT_MAX, mid; high++;
        while (low < high){
            mid = (low + high + 1) >> 1;
            if (is_ok (aa, bb, mid))    low = mid;
            else                        high = mid - 1;
        }
        low *= sgn;
        if (low > INT_MAX || low < INT_MIN) return INT_MAX;
        return low;
    }
};



class Solution {
public:
    int divide(int dividend, int divisor) {
        int sgn = 1;
        if (dividend > 0)   sgn *= (-1), dividend *= (-1);
        if (divisor > 0)    sgn *= (-1), divisor *= (-1);
        if (dividend == INT_MIN && divisor == -1){
            if (sgn == 1)   return INT_MAX;
            else            return INT_MIN;
        }
        int x = 0;
        while (dividend <= divisor){
            int b = divisor, d = 1;
            while (dividend - b <= b){
                b <<= 1; d <<= 1;
            }
            x += d; dividend -= b;
        }
        return x * sgn;
    }
};