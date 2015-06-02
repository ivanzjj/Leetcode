class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int low = 0, high = 0, sz = words.size ();
        while (low < sz){
            int cnt = 0, num = 0; high = low;
            bool add = false;
            while (high < sz && words[high].length() + cnt + add<= maxWidth){
                cnt += words[high].length () + add; num++;high++;
                add = true;
            }
            string tmp(maxWidth, ' ');
            if (num == 1){
                copy_n (words[low].begin (), words[low].length (), tmp.begin());
            }
            else{
                int tot = maxWidth - cnt;
                int pre = tot / (num - 1);
                int left = tot - (num - 1) * pre;
                int idx = 0;
                for (int i=0;i<num;i++){
                    copy_n (words[low + i].begin(), words[low + i].length (), tmp.begin() + idx);
                    idx += words[low + i].length () + 1;
                    if (high == sz) continue;
                    idx += pre;
                    if (i < left)
                        idx++;
                }
            }
            ans.push_back (tmp);
            low = high;
        }
        return ans;
    }
};