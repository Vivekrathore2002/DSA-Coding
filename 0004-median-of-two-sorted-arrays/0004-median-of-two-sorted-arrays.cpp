// Myself
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        vector<int> nums(n, 0);
        int i = 0, j = 0, k = 0;
        
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                nums[k] = nums1[i];
                i++;
            } else {
                nums[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            nums[k] = nums1[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            nums[k] = nums2[j];
            j++;
            k++;
        }
        
        if (n % 2 != 0) {
            return nums[n / 2];
        } else {
            return (nums[(n - 1) / 2] + nums[n / 2]) / 2.0;
        }
    }
};
