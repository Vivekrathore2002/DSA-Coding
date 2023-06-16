class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int altitude = 0;
        int mx = 0;
        
        for (int i = 0; i < n; i++) {
            altitude += gain[i];
            mx = max(mx, altitude);
        }
        
        return mx;
    }
};
