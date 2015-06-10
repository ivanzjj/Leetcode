class MinStack {
public:
    vector<int> vec;
    stack<int> st;

    void push(int x) {
        int idx = vec.size ();
        vec.push_back (x);
        if (st.empty () || vec[st.top()] > x)   st.push (idx);
    }

    void pop() {
        int idx = vec.size () - 1;
        vec.pop_back ();
        if (st.top () == idx)   st.pop();
    }

    int top() {
        return vec.back ();
    }

    int getMin() {
        return vec[st.top()];
    }
};
