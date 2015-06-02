/*
we can prove that for [i..j], the height of optimized rectangle is max {height[k]} k = i...j
we define two variable for every index i: L[i] and R[i].
L[i] is the smallest index which satisfy min {height[k]} >= height[i] for all k = L[i]...i
R[i] is the largest index which satisfy min {height[k]} >= height[i] for all k = i..R[i]
then the global optimized rectangle is max {(R[i] - L[i] + 1) * height[i]} for all i = 0...len-1

we use monotonous stack to computer L[i] and R[i]
iterate height from left to right, we maintain a monotonous increasing stack.
for every index i, pop stack's element is and only if height[ st.top() ] >= height[i]
after that, L[i] = i - st.top() - 1;
we can also computer R[i] which poping element from stack
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int sz = height.size (), idx;
        int *st = new int[sz];
        int top = 0;
        int *dp = new int[sz];
        fill_n (dp,sz,1);
        
        for (int i=0;i<sz;i++){
            while (top && height[st[top-1]] >= height[i]){
                dp[ st[top-1] ] += (i - 1 - st[top-1]); top--;
            }
            idx = top==0?0:st[top-1] + 1;
            dp[i] += i - idx;
            st[top++] = i;
        }
        while (top)    dp[ st[top-1] ] += sz - st[top-1] - 1, top--;
        int ans = 0;
        for (int i=0;i<sz;i++)  ans = max (ans, dp[i] * height[i]);
        return ans;
    }
};