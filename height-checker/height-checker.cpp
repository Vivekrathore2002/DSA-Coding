class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int count = 0;
        vector<int> expected(n, -1);  // Initialize with size n and default value -1

        for (int i = 0; i < n; i++) {
            expected[i] = heights[i];  // Assign the value to the corresponding index
        }

        sort(expected.begin(), expected.end());

        for (int i = 0; i < n; i++) {
            if (expected[i] != heights[i]) {
                count++;
            }
        }

        return count;
    }
};
