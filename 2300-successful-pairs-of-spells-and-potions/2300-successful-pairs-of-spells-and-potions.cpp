//mine approach
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);  // Initialize the answer array with 0s

        sort(potions.begin(), potions.end());  // Sort the potions array in ascending order

        for (int i = 0; i < n; i++) {
            int s = 0;
            int e = m - 1;

            while (s <= e) {
                int mid = s + (e - s) / 2;

                if ((long long)potions[mid] * spells[i] >= success) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            ans[i] = m - s;  // Store the number of successful pairs in ans[i]
        }

        return ans;
    }
};

