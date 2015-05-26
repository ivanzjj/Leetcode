class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        long long xx, yy = 0;
        xx = x;
        if (x < 0)  {
            flag = -1, xx *= (-1);
        }
        while (xx){
            yy = yy * 10 + xx % 10;
            xx /= 10;
        }
        yy = yy * flag;
        if (yy > INT_MAX || yy < INT_MIN)   return 0;
        else    return yy;
    }
};