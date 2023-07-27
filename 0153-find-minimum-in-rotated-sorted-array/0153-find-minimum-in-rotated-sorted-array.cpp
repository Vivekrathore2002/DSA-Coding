class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        // Check if the minimum element lies in the left half
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        // Check if the minimum element lies in the right half
        else {
            right = mid;
        }
    }
    return nums[left];
    }
};