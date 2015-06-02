class Solution {
public:
    string simplifyPath(string path) {
        int sz = path.length ();
        stack<string> st;
        if (sz && path[0] != '/')   return "";
        int now = 1, nxt;
        while (now < sz){
            nxt = now;
            for (;nxt < sz && path[nxt] != '/'; nxt++);
            string tmp = path.substr (now, nxt - now);
            if (tmp == ".."){
                if (!st.empty())    st.pop();
            }
            else if (tmp == ".") ;
            else if (tmp != "") st.push (tmp);
            now = nxt + 1;
        }
        string res = "";
        while (!st.empty ()){
            res = "/" + st.top () + res;
            st.pop();
        }
        if (res == "")  res = "/";
        return res;
    }
};