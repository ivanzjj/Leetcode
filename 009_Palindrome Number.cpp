class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x < 10) return true;
        int y = 0, tmp = 1;
        while (x/10 >= tmp){
            y = y * 10 + x % 10;
            x /= 10; tmp *= 10;
        }
        if (x >= tmp)   x /= 10;
        return x == y;
    }
};