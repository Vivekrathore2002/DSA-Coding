// //Chatgpt solution
// class Solution {
// public:
//     vector<int> findBall(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<int> res(n, -1);
//         // Iterate through each column of the grid
//         for(int j = 0; j < n; j++){
//             int i = 0;
//             int curr_j = j;
//             // Check if the ball falls through each row in the current column
//             while(i < m){
//                 // If the ball hits an obstacle, it can't move any further
//                 if(grid[i][curr_j] == 1 && (curr_j == n - 1 || grid[i][curr_j + 1] == -1)){
//                     break;
//                 }
//                 if(grid[i][curr_j] == -1 && (curr_j == 0 || grid[i][curr_j - 1] == 1)){
//                     break;
//                 }
//                 // If the ball can move to the next row, update the column position
//                 curr_j += grid[i][curr_j];
//                 i++;
//             }
//             // Store the final column position of the ball in the result vector
//             if(i == m){
//                 res[j] = curr_j;
//             }
//         }
//         return res;
//     }
// };


//The youtube(aceCoder Academy) solution
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> arr(m, -1);
        for(int i = 0; i < m; i++) {
            int x = 0, y = i;
            while(true) {
                if(x >= n) {
                    if(y >= 0 && y < m) {
                        arr[i] = y;
                    }
                    break;
                } else {
                    if(y + 1 < m && a[x][y] == 1 && a[x][y+1] == 1) {
                        x++;
                        y++;
                    } else if(y - 1 >= 0 && a[x][y] == -1 && a[x][y-1] == -1) {
                        x++;
                        y--;
                    } else {
                        break;
                    }
                }
            }
        }
        return arr;
    }
};
