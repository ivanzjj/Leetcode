/*
first check whether this two rectangle is not intersected
if two rectangle is intersected, then calculate the area of intersected part.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = 0;
        if (max (A,C) < min (E,G)
            || max (E,G) < min (A,C)
            || max (B,D) < min (F,H)
            || max (F,H) < min (B,D))
            left = 0;
        else {
            int a = min (C,G) - max (A,E);
            int b = min (D,H) - max (B,F);
            left = a * b;
        }
        return (C - A) * (D - B) + (G - E) * (H - F) - left;
    }
};