class Solution {
public:
    inline string to_string (int a){
        char tmp[100];
        sprintf (tmp, "%d", a);
        return tmp;
    }
    
    string countAndSay(int n) {
        string str[2];
        int pre = 1, now = 0;
        str[now] = "1";
        if (n == 1) return str[now];
        
        for (int i=2;i<=n;i++){
            pre ^= 1; now ^= 1;
            str[now] = "";
            int sz = str[pre].length (), cnt = 1;
            for (int i=1;i<sz;i++){
                if (str[pre][i] != str[pre][i-1]){
                    str[now] += to_string (cnt) + str[pre][i-1];
                    cnt = 1;
                }
                else
                    cnt++;
            }
            str[now] += to_string (cnt) + str[pre][sz - 1];
        }
        return str[now];
    }
};