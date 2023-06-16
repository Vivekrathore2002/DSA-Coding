class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        // Find the maximum element in the array
        int maxNum = *max_element(nums.begin(), nums.end());

        // Perform radix sort
        int exp = 1;
        vector<int> sortedNums(nums);
        while (maxNum / exp > 0) {
            vector<int> count(10, 0);

            for (int i = 0; i < n; i++)
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            for (int i = n - 1; i >= 0; i--) {
                int digit = (nums[i] / exp) % 10;
                sortedNums[count[digit] - 1] = nums[i];
                count[digit]--;
            }

            nums = sortedNums;
            exp *= 10;
        }

        // Calculate the maximum gap
        int maxGap = 0;
        for (int i = 1; i < n; i++) {
            int gap = nums[i] - nums[i - 1];
            maxGap = max(maxGap, gap);
        }

        return maxGap;
    }
};
