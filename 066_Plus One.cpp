class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size (), c = 1;
        vector<int> ans = digits;
        for (int i=sz-1;i>=0;i--){
            ans[i] += c;
            c = ans[i] / 10; ans[i] %= 10;
        }
        if (c){
            ans.insert (ans.begin(), c);
        } 
        return ans;
    }
};