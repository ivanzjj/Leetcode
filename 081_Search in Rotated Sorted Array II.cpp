/*
binary search

the solution is almost the same with "Search in Rotated Sorted Array"
the only difference is now the array may have duplicated element.
"Search in Rotated Sorted Array"'s solution won't work, because:

when we check whether the mid index located in left side of target
if nums[mid] = nums[low] = nums[high] and mid can also be in the part 2,
then we should deal with this situation alone.
*/
bool search(int* nums, int numsSize, int target) {
    if (numsSize == 0)  return false;
    if (numsSize == 1)  return nums[0] == target;
    int low = 0, high = numsSize - 1, mid;
    while (low < high){
        mid = (low + high + 1) >> 1;
        if (nums[mid] == target)    return true;
        if (nums[low] == nums[high] && nums[low] == nums[mid]){
            return search (nums + low, mid - low , target) || search (nums+mid+1, high - mid, target);
        }
        else if (target >= nums[low]){
            if (nums[mid] >= nums[low] && nums[mid] <= target)  low = mid;
            else            high = mid - 1;
        }
        else{
            if (nums[mid] <= nums[high] && nums[mid] > target)  high = mid - 1;
            else        low  = mid;
        }
    }
    return nums[low] == target;
}