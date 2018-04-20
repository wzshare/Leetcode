#include "../libstruct.h"

using namespace std;

/*
 * NO.4
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m+n)).
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int minidx = 0, maxidx = m, i, j, a, mid = (m + n + 1) >> 1, b;
        while (minidx <= maxidx)
        {
            i = (minidx + maxidx) >> 1;
            j = mid - i;
            if (i<m && j>0 && nums2[j-1] > nums1[i]) minidx = i + 1;
            else if (i>0 && j<n && nums2[j] < nums1[i-1]) maxidx = i - 1;
            else
            {
                if (i == 0) a = nums2[j-1];
                else if (j == 0) a = nums1[i - 1];
                else a = max(nums1[i-1],nums2[j-1]);
                break;
            }
        }
        if (((m + n) & 1)) return a;
        if (i == m) b = nums2[j];
        else if (j == n) b = nums1[i];
        else b = min(nums1[i],nums2[j]);
        return (a + b) / 2.;
    }
};

//out: 5
int main(int argc, char const *argv[])
{
    vector<int> nums1 = {3, 4, 5, 8};
    vector<int> nums2 = {1, 2, 6, 9, 11};
    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}