/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int find_left (vector<Interval>& intervals, int val){
        int low = 0, high = intervals.size () - 1, mid;
        while (low < high){
            mid = (low + high) >> 1;
            if (intervals[mid].end >= val)    high = mid;
            else        low = mid + 1;
        }
        if (intervals[low].end >= val)  return low;
        return -1;
    }
    int find_right (vector<Interval>& intervals, int val){
        int low = 0, high = intervals.size () - 1, mid;
        while (low < high){
            mid=  (low + high + 1) >> 1;
            if (intervals[mid].start <= val)    low = mid;
            else        high = mid-1;
        }
        if (intervals[low].start <= val)    return low;
        return -1;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector <Interval> ans;
        if (intervals.size () == 0){
            ans.push_back (newInterval);
            return ans;
        }
        int x = find_left (intervals, newInterval.start);
        if (x == -1){
            ans = intervals;
            ans.push_back (newInterval);
            return ans;
        }
        int y = find_right (intervals, newInterval.end);
        if (y == -1){
            ans = intervals;
            ans.insert (ans.begin(), newInterval);
            return ans;
        }
        if (x > y){
            ans = intervals;
            ans.insert (ans.begin() + x, newInterval);
            return ans;
        }
        ans = intervals;
        int left = min (intervals[x].start, newInterval.start);
        int right = max (intervals[y].end, newInterval.end);
        ans.insert (ans.begin()+x, Interval(left, right));
        ans.erase (ans.begin()+x+1, ans.begin()+y+2);
        return ans;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0, sz = intervals.size ();
        for (;i<sz && intervals[i].end < newInterval.start;i++) ans.push_back (intervals[i]);
        int s = newInterval.start, e = newInterval.end;
        
        for (;i<sz;i++){
            if (intervals[i].start > e) break;
            s = min (s, intervals[i].start);
            e = max (e, intervals[i].end);
        }
        ans.push_back (Interval (s,e));
        for (;i<sz;i++) ans.push_back (intervals[i]);
        return ans;
    }
};
