/*
every bit in a mean whether there is one 1
every bit in b mean whether there is two 1s
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i=0,sz=nums.size();i<sz;i++){
            int na = a;
            a = (a^(a&nums[i])) | (~(a^b)&nums[i]);
            b = (na&nums[i]) | (b^(b&nums[i]));
        }
        return a;
    }
};