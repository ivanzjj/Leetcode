class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size ();
        int _min = nums[0], _max = nums[0];
        int ans = _max;
        
        for (int i=1;i<N;i++){
            int a = nums[i], b = nums[i];
            if (nums[i] > 0){
                a = max (a, _max * nums[i]);
                b = min (a, _min * nums[i]);
            }
            else {
                a = max (a, _min * nums[i]);
                b = min (b, _max * nums[i]);
            }
            _max = a; _min = b;
            ans = max (ans, _max);
        }
        return ans;
    }
};
