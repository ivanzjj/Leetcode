/*
	f[i][j] : whether p[0...i-1] and s[0...j-1] matchs
	we regard "a*" as one character
	if p[i-1] == '*'
		f[i][j] = f[i-1][j] || (f[i][j-1] && match (p[i-2], s[j-1]))
	else
		f[i][j] = f[i-1][j-1] && match (p[i-1], s[j-1])
*/
class Solution {
public:
    bool match (char a, char b){
        return a == '.' || a == b;
    }
    bool isMatch(const char *s, const char *p) {
        int sl = strlen (s), pl = strlen (p);
        vector <bool> f (sl+1, false);
        f[0] = true;
        
        while (*p){
            char c = *(p++);
            bool is_star = (*p) == '*';
            if (is_star){
                for (int j=1;j<=sl;j++)     f[j] = f[j] || (f[j-1] && match (c, s[j-1]));
                p++;
            }
            else{
                for (int j=sl;j>0;j--)      f[j] = f[j-1] && match (c, s[j-1]);
                f[0] = false;
            }
        }
        return f[sl];
    }
};