class Solution {
public:
    int myAtoi(string str) {
        int len = str.length ();
        int i;
        for (i=0;i<len && str[i]==' ';i++);
        int sgn = 1, cnt = 0;
        long long x = 0;
        for (;i<len;i++){
            if (str[i]=='+' || str[i]=='-'){
                if (cnt)   break;
                if (x != 0)     break;
                sgn = (str[i] == '+' ? 1 :-1); cnt++;
            }   
            else if (str[i]>='0' && str[i]<='9'){
                x = x * 10 + str[i] - '0';
                if (x * sgn > INT_MAX)  return INT_MAX;
                if (x * sgn < INT_MIN)  return INT_MIN;
            }
            else
                break;
        }
        x = x * sgn;
        if (x > INT_MAX)    x = INT_MAX;
        else if (x < INT_MIN)   x = INT_MIN;
        return x;
    }
};