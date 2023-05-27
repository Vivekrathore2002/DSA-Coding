class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        // Create a vector to check if we visited all rooms or not
        vector<bool> visited(n, false);

        // Create a queue for BFS and let us visit room 0 first
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            // Get current room
            int index = q.front();
            q.pop();

            // If already visited, skip it because we already have all the keys from the index
            if(visited[index]) continue;

            // Mark the room visited and add all rooms which can be unlocked into the queue
            visited[index] = true;
            for(auto i: rooms[index]) q.push(i);
        }

        // If any room is unvisited, then we can return false else true
        for(auto i: visited) {
            if(!i) return false;
        }
        return true;
    }
};