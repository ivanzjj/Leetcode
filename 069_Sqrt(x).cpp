class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)  return INT_MIN;
        int low = 0, high = x;
        long long mid;
        while (low < high){
            mid = ((long long)low + high + 1) >> 1;
            if ((long long)(mid) * mid > x)   high = mid - 1;
            else            low = mid;
        }
        return low;
    }
};


class Solution {
public:
    double eps = 1e-6;
    inline bool Equal (double a, double b){
        double c = a - b;
        if ( c<=eps && c>=-eps )    return true;
        else        return false;
    }
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        double y = 1.0, ny;
        
        while (true){
            ny = (x / y + y) / 2;
            if (Equal(ny, y))    break;
            y = ny;
        }
        return (int)ny;
    }
};