/*
binary search
we split the array into two parts (maybe only one part)
part 1: [0...i], satisfy : nums[i] > nums[i-1] for all 1....i, which i is maximum.
part 2: the rest part of the array

for every iteration in binary search, we do:
1 check whether target is in part 1 or 2
2 according the value of nums[mid], shut down half of the search interval

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size () - 1, mid;
        while (low < high){
            mid = (low + high + 1) >> 1;
            if (nums[mid] == target)    return mid;
            if (target >= nums[low]){
                // 1
                if (nums[mid] >= nums[low] && nums[mid] <= target)  low = mid;
                else            high = mid - 1;
            }
            else {
                // 2
                if (nums[mid] <= nums[high] && nums[mid] > target)  high = mid - 1;
                else        low = mid;
            }
        }
        return nums[low] == target ? low : -1;
    }
};