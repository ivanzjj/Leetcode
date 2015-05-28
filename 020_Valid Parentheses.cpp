class Solution {
public:
    inline int get_int (char c){
        if (c == '(' || c == ')')   return 0;
        if (c == '[' || c == ']')   return 1;
        if (c == '{' || c == '}')   return 2;
    }
    bool isValid(string s) {
        stack <int> st;
        for (int i=0,sz=s.length ();i<sz;i++){
            if (s[i] == '(' || s[i] == '[' || s[i]=='{')
                st.push (get_int (s[i]));
            else {
                if (st.empty () || st.top() != get_int(s[i]))   return false;
                st.pop();
            }
        }
        return st.empty ();
    }
};