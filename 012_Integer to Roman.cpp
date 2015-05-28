class Solution {
public:
    char c1[5] = {'I', 'X', 'C', 'M'};
    char c2[5] = {'V', 'L', 'D'};
    
    string intToRoman(int num) {
        string ans = "", tmp;
        int idx = 0;
        while (num){
            int a = num % 10;
            tmp = "";
            if (a >= 1 && a <= 3){
                for (int i=0;i<a;i++)   tmp += c1[idx];
            }
            else if (a == 4)    tmp += c1[idx], tmp += c2[idx];
            else if (a >= 5 && a < 9){
                tmp += c2[idx];
                for (int i=0;i<(a - 5);i++) tmp += c1[idx];
            }
            else if (a == 9)
                tmp += c1[idx], tmp += c1[idx+1];
            idx++;
            ans = tmp + ans;
            num /= 10;
        }
        return ans;
    }
};