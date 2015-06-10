class Solution {
public:
    int _get (int n){
        int a = 0, b;
        while (n){
            b = n % 10;
            a += b * b;
            n /= 10;
        }
        return a;
    }
    bool isHappy(int n) {
        bool vis[1000];
        memset (vis, false, sizeof(vis));
        int a = _get (n);
        vis [a] = true;
        while (a != 1){
            a = _get (a);
            if (vis[a]) return false;
            vis[a] = true;
        }
        return true;
    }
};
