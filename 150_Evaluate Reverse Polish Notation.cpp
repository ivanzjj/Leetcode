class Solution {
public:
    int do_it (int a, char c, int b){
        if (c == '+')   return a + b;
        else if (c == '-')  return a - b;
        else if (c == '*')  return a * b;
        else        return a / b;
    }
    char num[1000];
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto token : tokens){
            if (token.size()==1 && (token[0]=='+' || token[0]=='-' || token[0]=='*' || token[0]=='/')){
                int b = st.top(); st.pop ();
                int a = st.top(); st.pop ();
                int c = do_it (a, token[0], b);
                st.push (c);
            }
            else{
                sprintf (num, "%s",token.c_str());
                int a;
                sscanf (num, "%d", &a);
                st.push (a);
            }
        }
        return st.top();
    }
};
