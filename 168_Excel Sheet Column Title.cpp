class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n){
            char c = (n - 1) % 26 + 'A';
            ans = c + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};
