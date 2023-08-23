//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// https://www.youtube.com/watch?v=yf3oUhkvqA0
class Solution {
public:
    int bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>&visited, vector<vector<int>>& grid, int rows, int columns){
        int directions[5] = {0,-1,0,1,0};
        int time=0;
        while(!q.empty()){
            pair<pair<int,int>,int>pr = q.front();
            q.pop();
            time = pr.second;
            for(int k=0; k<4; k++){
                int nrow = pr.first.first+directions[k];
                int ncol = pr.first.second+directions[k+1];
                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<columns && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    grid[nrow][ncol] = 2;
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int ans = 0;
        vector<vector<int>>visited(rows,vector<int>(columns));
        queue<pair<pair<int,int>,int>>q; //[{r,c},{t}]
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 2 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        ans = bfs(q,visited,grid,rows,columns);
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends