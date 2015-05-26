/* O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length ();
        string tmp = "", ans = "";
        if (sz == 0)    return ans;
        for (int i=0;i<sz;i++)  tmp = tmp + '#' + s[i];
        tmp += '#';
        int _max = 0;
        for (int i=0;i<sz*2;i++){
            int low = i - 1, high = i + 1;
            while (low>=0 && high<sz*2+1 && tmp[low] == tmp[high])  low--, high++;
            if (_max < high - low - 1){
                _max = high - low - 1;
                ans = s.substr ((low + 1)/2, _max/2);
            }
        }
        return ans;
    }
};
*/

/* O(N) */
class Solution {
public:
    string longestPalindrome(string s) {
        string tmp = s + s + "#";
        int sz = s.length ();
        if (sz == 0)    return "";
        for (int i = 0 ;i < sz; i++)    tmp[i<<1] = '#', tmp[i<<1|1] = s[i];
        vector <int> p(sz*2+1, 1);
        int idx = 0, mx = 1;
        int start_pos, len = 0;
        
        for (int i=1;i < sz*2;i++){
            if (i < mx)
                p[i] = min (p[2*idx - i], mx - i);
            else 
                p[i] = 1;
            while (i - p[i]>=0 && i+p[i]<sz*2+1 && tmp[i-p[i]] == tmp[i+p[i]])  p[i]++;
            if (i + p[i] > mx){
                idx = i; mx = i + p[i];
            }
            if (2*p[i] - 1 > len){
                len = 2 * p[i] - 1;
                start_pos = (i - p[i]);
            }
        }
        return s.substr ((start_pos+1)>>1, len / 2);
    }
};
