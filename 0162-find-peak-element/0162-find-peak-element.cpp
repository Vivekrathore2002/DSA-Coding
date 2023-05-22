class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // We are on the descending side of the peak, so the peak is either at mid or on the left side
                right = mid;
            } else {
                // We are on the ascending side of the peak, so the peak is on the right side
                left = mid + 1;
            }
        }

        return left;
    }
};
