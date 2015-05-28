class Solution {
public:
    vector <string> ans;
    vector <int>    index;
    vector <string> ref;
    void dfs (string &digits, int now, int sz){
        if (now == sz){
            string str = "";
            for (int i=0;i<sz;i++){
                str += ref[ digits[i]-'0' ][ index[i] ];
            }
            ans.push_back (str);
            return;
        }
        index.push_back (0);
        int dd = digits[now] - '0';
        for (int i=0;i<ref[dd].length ();i++){
            index[now] = i;
            dfs (digits,now+1,sz);
        }
    }
    vector<string> letterCombinations(string digits) {
        ref.clear();
        ans.clear();
        ref.push_back (" "); ref.push_back ("X"); ref.push_back ("abc");ref.push_back ("def");ref.push_back ("ghi");ref.push_back ("jkl");ref.push_back ("mno");ref.push_back ("pqrs");ref.push_back ("tuv");ref.push_back ("wxyz");
        index.clear ();
        int sz = digits.length ();
        if (sz == 0)        return ans;
        dfs (digits,0,sz);
        return ans;
    }
};