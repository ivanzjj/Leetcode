class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i=30;i>=0;i--){
            if ((m >> i) ^ (n >> i)){
                return ans;
            }
            else if (m >> i & 1){
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
