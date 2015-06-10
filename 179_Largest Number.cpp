bool cmp (int a, int b){
    ostringstream out1, out2;
    out1 << a << b;
    out2 << b << a;
    return out1.str () > out2.str ();
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort (nums.begin(),nums.end(),cmp);
        ostringstream out;
        for (int i=0;i<nums.size();i++) out << nums[i];
        string ans = out.str ();
        int idx = 0, sz = ans.length ();
        for (;idx<sz && ans[idx] == '0'; idx++);
        if (idx == sz)  return "0";
        else        return ans.substr (idx);
    }
};
