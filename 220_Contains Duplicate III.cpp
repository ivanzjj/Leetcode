/*
 use a set to maintain k elements, for every element nums[i], 
 find the biggest value less than nums[i], and check whether the difference is less or equal that t.
 find the least value greater than nums[i], and check the difference also.

 time complexisity: O(NlogN)
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size ();
        set<int> s;
        set<int>::iterator _left, _right;
        s.clear ();
        for (int i=0;i<sz;i++){
            _left = s.lower_bound (nums[i]);
            _right = _left;
            if (_left != s.begin()){
                _left--;
                if ((long long)nums[i] - (*_left) <= t)  return true;
            }
            if (_right != s.end () && (long long)(*_right) - nums[i] <= t)   return true;
            s.insert (nums[i]);
            if (i-k >= 0)   s.erase (nums[i - k]);
        }
        return false;
    }
};


/*
 if abs (nums[i] - nums[j]) <= t,
 then abs (nums[i] - nums[j]) / t <= 1
 then abs (floor(nums[i]/t) - floor(nums[j]/t)) <= 1
 then floor(nums[i]/t) equals floor(nums[j]/t)-1 or floor(nums[j]/t) or floor(nums[j]/t)+1
 
 we use the converse-negative proposition.
 that is:
 if floor (nums[i]/t) is not equal floor (nums[j]/t)-1 or floor (nums[j]/t) or floor (nums[j]/t) + 1
 then abs (nums[i] - nums[j]) > t
 */

class Solution {
public:
    long long my_abs (int& a, int& b){
        long long aa = (long long)a - b;
        return aa < 0 ? -aa : aa;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size ();
        if (sz == 0 || k == 0)    return false;
        unordered_map<int,int> mp;  // we do not use multimap, because if there exist two index i,j, st. nums[i]/t == nums[j]/t, then abs(nums[i] - nums[j]) <= t
        if (t == 0){
            for (int i=0;i<sz;i++){
                if (mp.find (nums[i]) != mp.end())  return true;
                mp[ nums[i] ] = 1;
                if (i-k>=0) mp.erase (nums[i - k]);
            }
            return false;
        }
        for (int i=0;i<sz;i++){
            int a = nums[i] / t;
            if (mp.find (a - 1) != mp.end () && my_abs(mp[a - 1], nums[i]) <= t)    return true;
            if (mp.find (a) != mp.end () && my_abs(mp[a], nums[i]) <= t)    return true;
            if (mp.find (a + 1) != mp.end () && my_abs(mp[a + 1], nums[i]) <= t)    return true;
            if (i - k >= 0) mp.erase (nums[i - k] / t);
            mp[a] = nums[i];
        }
        return false;
    }
};
