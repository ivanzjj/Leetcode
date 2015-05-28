class Solution {
public:
    int find (string &a, string &b){
        int cnt = 0;
        for (int i=0,sa=a.length (), sb=b.length ();i<sa && i<sb && a[i]==b[i];i++,cnt++);
        return cnt;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size () == 0)  return "";
        if (strs.size () == 1)  return strs[0];
        int _min = strs[0].length ();        
        for (int i=0, sz=strs.size ();i<sz-1;i++){
            _min = min (_min, find (strs[i],strs[i+1]));    
        }
        return strs[0].substr (0, _min);
    }
};