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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort (intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start || (a.start == b.start && a.end > b.end);
        });
        vector<Interval> ans;
        int idx = 0, sz = intervals.size (), new_idx, left, right;
        while (idx < sz){
            new_idx = idx + 1;
            left = intervals[idx].start; right = intervals[idx].end;
            while (new_idx < sz && !(intervals[new_idx].start > right) ){
                right = max(right, intervals[new_idx].end); 
                new_idx++;
            }
            ans.push_back (Interval(left, right));
            idx = new_idx;
        }
        return ans;
    }
};