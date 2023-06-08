class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        int r = row - 1; // Start from the last row
        int c = 0; // Start from the first column

        while (r >= 0 && c < col) {
            if (grid[r][c] < 0) {
                count += (col - c); // Increment count by remaining columns
                r--; // Move to the previous row
            } else {
                c++; // Move to the next column
            }
        }

        return count;
    }
};
