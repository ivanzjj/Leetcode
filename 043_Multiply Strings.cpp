class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length (), len2 = num2.length ();
        if (len1 == 0)  return num2;
        if (len2 == 0)  return num1;
        
        int sgn = 1;
        if (num1[0]=='-')   sgn *= (-1), num1 = num1.substr(1), len1--;
        if (num1[0]=='+')   num1 = num1.substr(1);
        if (num2[0]=='-')   sgn *= (-1), num2 = num2.substr(1), len2--;
        if (num2[0]=='+')   num2 = num2.substr(1);
        
		reverse (num1.begin(), num1.end());
		reverse (num2.begin(), num2.end());
		
		string ans(len1 + len2, 0);
		
		for (int i=0;i<len1;i++){
		    int a = num1[i] - '0', b;
            int t = 0;
            for (int j=0;j<len2;j++){
                b = a * (num2[j] - '0') + t + ans[i + j];
                t = b / 10; b %= 10;
                ans[i + j] = b;
            }
            int idx = i + len2;
            while (t){
                b = ans[idx] + t;
                t = b / 10; b %= 10;
                ans[idx] = b; idx++;
            }
		}
        for (int i=len1+len2-1;i>=0;i--){
            if (ans[i] == 0)    continue;
            ans.resize (i + 1);
            for (;i>=0;i--){
                ans[i] += '0';
            }
            reverse (ans.begin(), ans.end());
            if (sgn == -1)  return "-" + ans;
            else            return ans;
        }
        return "0";
    }
};