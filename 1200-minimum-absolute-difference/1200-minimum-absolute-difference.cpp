//My solution with little help of chatgpt also
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());  // Sort the array in ascending order
        int minDiff = INT_MAX;
        
        // Find the minimum absolute difference
        for (int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, abs(arr[i] - arr[i-1]));
        }
        
        // Find pairs with the minimum absolute difference
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i-1]) == minDiff) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        
        return ans;
    }
};
