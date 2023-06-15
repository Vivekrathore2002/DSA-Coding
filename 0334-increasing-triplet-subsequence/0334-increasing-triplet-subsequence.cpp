// https://www.youtube.com/watch?v=90tYQ5jNVPo&ab_channel=CodewithAlisha
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;  // Initialize the first smallest element
        int second = INT_MAX; // Initialize the second smallest element

        for (int num : nums) {
            if (num <= first) {
                first = num; // Update the first smallest element
            } else if (num <= second) {
                second = num; // Update the second smallest element
            } else {
                return true; // We found an increasing triplet
            }
        }

        return false; // No increasing triplet found
    }
};
