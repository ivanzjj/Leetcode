/*
conclusion:
1, all valid parentheses end with ')'
2, if 0..i is not valid parentheses, then every j's(j > i) left bound is big than i

Algorithm:
we maintain a stack, traverse s from the left to right.
when arrive at index i, the top element of stack is
the smallest index which satisfy [st.top()+1, i] is valid,
and the length is i - st.top (), so we update the answer once
we encounter a ')'.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.length ();
        stack <int> st;
        st.push (-1);
        int ans = 0;
        for (int i=0;i<sz;i++){
            if (s[i] == '(')    st.push (i);
            else{
                if (st.size () == 1)    st.top () = i;
                else{
                    st.pop();
                    ans = max (ans, i - st.top());
                }
            }
        }
        return ans;
    }
};