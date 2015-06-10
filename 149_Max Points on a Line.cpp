/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}tt
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    bool is_ok (Point p1, Point p2, Point p3){
        Point v1, v2;
        v1.x = p1.x - p2.x;
        v1.y = p1.y - p2.y;
        v2.x = p3.x - p2.x;
        v2.y = p3.y - p2.y;
        return (v1.x * v2.y - v2.x * v1.y == 0);
    }
    int maxPoints(vector<Point>& points) {
        int N = points.size ();
        if (N == 0) return 0;
        int ans = 1;
        bool ok = false;
        for (int i=0;i<N;i++){
            for (int j=i+1;j<N;j++) if (points[i].x != points[j].x || points[i].y != points[j].y){
                ok = true;
                int tmp = 0;
                for (int k=0;k<N;k++){
                    if (is_ok (points[i], points[j], points[k]))    tmp++;
                }
                ans = max (ans, tmp);
            }
        }
        if (!ok)    return N;
        return ans;
    }
};


/*
time complexity is : O(N^2*logN)
enumerate a point and sort other points using polar angle sort
*/
bool cmp (const Point& a, const Point& b){
    return a.x * b.y - a.y * b.x > 0;
}
class Solution {
public:
    inline bool same_line (const Point& a, const Point& b){
        return a.x * b.y == a.y * b.x;
    }
    int solve (vector<Point>& vec){
        if (vec.size () == 0)   return 0;
        sort (vec.begin(), vec.end(), cmp);
        int _max = 0, cnt = 1, idx = 0;
        for (int i=1;i<vec.size();i++){
            if (same_line(vec[idx], vec[i])) cnt++;
            else{
                _max = max (_max, cnt);
                cnt = 1; idx = i;
            }
        }
        _max = max (_max, cnt);
        return _max;
    }
    int maxPoints(vector<Point>& points) {
        int N = points.size ();
        if (N < 3)  return N;
        int ans = 0;
        for (auto o : points){
            vector<Point> vec;
            int cnt = 0;
            for (auto p : points){
                if (o.x==p.x && o.y==p.y){
                    cnt++; continue;
                }
                int xx = p.x - o.x, yy = p.y - o.y;
                if (yy<0 || (yy==0 && xx<0))    xx *= (-1), yy *= (-1);
                vec.push_back (Point(xx,yy));
            }
            ans = max (ans, cnt + solve (vec));
        }
        return ans;
    }
};
