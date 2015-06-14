class Solution {
public:
    stack<int> num;
    stack<char> ope;
    void update (){
        while (!ope.empty() && ope.top() != '(' && num.size () >= 2 ){
            char c = ope.top (); ope.pop();
            int b = num.top (); num.pop();
            int a = num.top (); num.pop();
            if (c == '+'){
                num.push (a + b);
            }
            else
                num.push (a - b);
        }
    }
    int calculate(string s) {
        int idx = 0, a, b;
        for (int i=0,sz=s.length();i<sz;i++){
            if (s[i] != ' ')    s[idx++] = s[i];
        }
        s.resize (idx);
        for (int i=0;i<idx;i++){
            if (s[i] == '(')    ope.push ('(');
            else if (s[i] == ')'){
                if (ope.top () == '('){
                    ope.pop();
                    update ();
                }
                else{
                    update ();
                    ope.pop ();
                    update ();
                }
            }
            else if (s[i] == '+' || s[i]=='-')  ope.push (s[i]);
            else{
                a = s[i] - '0';
                for (i++;i<idx && s[i]>='0' && s[i]<='9';i++) a = a * 10 + s[i] - '0';
                i--;
                num.push (a);
                update ();
            }
            
        }
        return num.top ();
    }
};