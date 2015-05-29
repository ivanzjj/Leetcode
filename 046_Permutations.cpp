class Solution {
public:
    bool next_ (vector<int>& tmp){
        int sz = tmp.size ();
        int idx = sz - 1;
        for (;idx>0 && tmp[idx] < tmp[idx-1]; idx--);
        if (idx == 0)   return false;
        int i = sz - 1;
        for (;tmp[i] < tmp[idx-1]; i--);
        swap (tmp[i], tmp[idx-1]);
        reverse (tmp.begin()+idx, tmp.end ());
        return true;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp = nums;
        sort (tmp.begin(), tmp.end());
        for (;;){
            ans.push_back (tmp);
            if (!next_ (tmp))   break;
        }
        return ans;
    }
};