class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ans;
        map <string, int> mp;
        for (int i=0,sz=strs.size ();i<sz;i++){
            string s = strs[i];
            sort (s.begin(), s.end());
            if (mp.count (s) == 0){
                mp[s] = i;
                continue;
            }
            else if (mp[s] != -1){
                ans.push_back ( strs[mp[s]] );
                mp[s] = -1;
            }
            ans.push_back (strs[i]);
        }   
        return ans;
    }
};