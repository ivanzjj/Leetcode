class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> ans;
        map <string, int> goal;
        for (auto& it : words)  goal[it]++;
        int words_num = words.size ();
        int words_len = words[0].length ();
        
        for (int i=0, sz=s.length ();i<sz && i<words_len;i++){
            map <string, int> now;
            int cnt = 0;
            for (int j=0;i+j*words_len + words_len<=sz;j++){
                string sub_ = s.substr (i+j*words_len, words_len);
                if (goal.count (sub_) != 0){
                    now[sub_]++;
                    if (now[sub_] <= goal[sub_])    cnt++;
                }
                if (cnt == words_num){
                    ans.push_back (i + (j - words_num  + 1)*words_len);
                }
                if (j < words_num - 1)  continue;
                sub_ = s.substr (i + (j - words_num + 1)*words_len, words_len);
                if (goal.count (sub_) != 0){
                    if (now[sub_] <= goal[sub_])    cnt--;
                    now[sub_]--;
                }
            }
        }
        return ans;
    }
};