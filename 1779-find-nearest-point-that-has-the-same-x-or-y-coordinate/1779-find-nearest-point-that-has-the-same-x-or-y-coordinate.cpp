class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
       int ans = -1, mdis = INT_MAX;
        for(int i=0; i<points.size(); i++) {
            if(points[i][0] == x or points[i][1] == y) {
                int dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(dis < mdis) mdis = dis, ans = i;
            }
        }
        return ans;
    }
};