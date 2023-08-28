// https://www.youtube.com/watch?v=SCz-1TtYxDI
class Solution {
public:
	int lowerBound(vector<int>& mat, int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = n;
        sort(mat.begin(), mat.end());

        while (low <= high) {
            int mid = (low + high) / 2;

            if (mat[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count_max = -1;
        int no_of_ones = 0;
        int index = -1;
        vector<int> output(2);
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            no_of_ones = m - lowerBound(mat[i], m, 1);

            if (no_of_ones > count_max) {
                count_max = no_of_ones;
                index = i;
                output[0] = index;
                output[1] = count_max;
            }
        }
        return output;
    }
};