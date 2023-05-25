class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0]; 
        });
        
        int i;
        for (i = 0; i < intervals.size() - 1; i++) {
            // no overlap
            if (intervals[i][1] < intervals[i+1][0]) {
                result.push_back(intervals[i]);
                continue;
            }
            // overlap
            intervals[i+1][0] = intervals[i][0];
            intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
        }
        result.push_back(intervals[i]);

        return result;
    }
};