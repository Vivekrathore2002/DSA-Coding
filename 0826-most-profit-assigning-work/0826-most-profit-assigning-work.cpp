//My Approach + chatgpt
class Solution {
public:
    int binary_search(vector<pair<int, int>>& jobs, int x) {
        int n = jobs.size();
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (jobs[mid].first > x)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return e;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs; // pairs of (difficulty, profit)
        // Create pairs of (difficulty, profit)
        for (int i = 0; i < n; i++)
            jobs.push_back({difficulty[i], profit[i]});
        // Sort jobs based on difficulty in ascending order
        sort(jobs.begin(), jobs.end());
        int maxProfit = 0;
        int sum = 0;
        // Update the maximum profit for each difficulty level
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, jobs[i].second);
            jobs[i].second = maxProfit;
        }
        int m = worker.size();
        // Find the maximum profit for each worker
        for (int i = 0; i < m; i++) {
            int idx = binary_search(jobs, worker[i]);
            if (idx >= 0)
                sum += jobs[idx].second;
        }
        return sum;
    }
};