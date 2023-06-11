// https://www.youtube.com/watch?v=_rgTlyky1uQ&ab_channel=takeUforward
// There are three basic approaches Reccursion,Memoizatiom,Tabulation
// 1.Reccursion
// class Solution {
// public:
// int f(int i,int j,vector<vector<int>>& grid){
//     if(i==0 && j== 0) return grid[i][j];
//     if(i<0 || j<0) return 1e9;
//     int up = grid[i][j] + f(i-1,j,grid);
//     int left = grid[i][j] + f(i,j-1,grid);
//     return min(left,up);
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         return f(n-1,m-1,grid);
//     }
// };

// 2.Memoization
// class Solution {
// public:
// int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
//     if(i==0 && j== 0) return grid[i][j];
//     if(i<0 || j<0) return 1e9;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int up = grid[i][j] + f(i-1,j,grid,dp);
//     int left = grid[i][j] + f(i,j-1,grid,dp);
//     return dp[i][j] = min(left,up);
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,grid,dp);
//     }
// };

// 3.Tabulation
class Solution {
public:
int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
    if(i==0 && j== 0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = grid[i][j] + f(i-1,j,grid,dp);
    int left = grid[i][j] + f(i,j-1,grid,dp);
    return dp[i][j] = min(left,up);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        // return f(n-1,m-1,grid,dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up +=1e9;
                    int left = grid[i][j];
                    if(j>0) left +=dp[i][j-1];
                    else left+=1e9;
                    dp[i][j] = min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};