/*
 O(N)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size ();
        for (int i=0;i<sz;i++){
            if ((i==0 || nums[i]>nums[i-1]) && (i+1==sz || nums[i]>nums[i+1]) ) return i;
        }
        return -1;
    }
};


/*
 O(logN)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size () - 1, mid, sz = nums.size ();
        bool con1, con2;
        while (low <= high){
            mid = (low + high) >> 1;
            if ((con1=(mid==0 || nums[mid-1] < nums[mid])) && (con2=(mid==sz-1 || nums[mid]>nums[mid+1])))  return mid;
            if (con1)    low = mid + 1;
            else            high = mid - 1;
        }
        return -1;
    }
};
