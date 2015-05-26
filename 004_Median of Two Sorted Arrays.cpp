/*
class Solution {
public:
    int m, n;
    int calc (vector<int>& nums1, vector<int> &nums2, int K){
        if (m == 0)     return nums2[K-1];
        if (n == 0)     return nums1[K-1];
        int low = 0, high = m, mid, mid2;
        while (low < high) {
            mid = low + (high - low) / 2;
            mid2 = K - 1 - mid;
            if (mid2 < 0)   high = mid - 1;
            else if (mid2 > n)  low = mid + 1;
            else{
                if (mid2==0 || nums1[mid] >= nums2[mid2 - 1])
                    high = mid;
                else
                    low = mid + 1;
            }
        }
        mid2 = K - 1 - low;
        if (low == m)   return nums2[mid2];
        else if (mid2 == n)     return nums1[low];
        return min (nums1[low], nums2[mid2]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size (), n = nums2.size ();
        if ((m + n) & 1)
            return calc (nums1, nums2, (m + n)/2+1);
        else
            return (calc (nums1, nums2, (m + n)/2) + calc (nums1, nums2, (m+n)/2+1) ) / 2.0;
    }
};
*/


int Min (int a, int b){
    return a > b ?b :a;
}
int findkth (int *nums1, int n, int *nums2, int m, int k){
    if (n > m)  return findkth (nums2, m, nums1, n, k);
    if (n == 0)     return nums2[k-1];
    if (m == 0)     return nums1[k-1];
    if (k == 1)     return Min (nums1[0], nums2[0]);
    int la = Min (k / 2, n);
    int lb = k - la;
    if (nums1[la - 1] >= nums2[lb - 1])     return findkth (nums1, n, nums2+lb, m-lb, k - lb);
    else                                    return findkth (nums1+la, n-la, nums2, m, k - la);
}
double findMedianSortedArrays(int* nums1, int n, int* nums2, int m) {
    if ((n + m) & 1)
        return findkth (nums1, n, nums2, m, (n+m)/2+1);
    else
        return (findkth (nums1, n, nums2, m, (n+m)/2) + findkth (nums1, n, nums2, m, (n+m)/2+1)) / 2.0;
}
