class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que[now].push (x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (que[now].size () > 1){
            que[pre].push (que[now].front());
            que[now].pop();
        }
        que[now].pop();
        now ^= 1; pre ^= 1;
    }

    // Get the top element.
    int top() {
        while (que[now].size () > 1){
            que[pre].push (que[now].front());
            que[now].pop();
        }
        return que[now].front ();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que[now].empty () && que[pre].empty ();
    }
    queue<int> que[2];
    int pre = 0, now = 1;
};