class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size ();
        if (sz < 3) return 0;
        int idx = 0;
        for (int i=1;i<sz;i++)  if (height[i] > height[idx])    idx = i;
        int ans = 0, _max = 0;
        for (int i=0;i<idx;i++){
            _max = max (_max, height[i]);
            ans += (_max - height[i]);
        }
        _max = 0;
        for (int i=sz-1;i>idx;i--){
            _max = max (_max, height[i]);
            ans += (_max - height[i]);
        }
        return ans;
    }
};