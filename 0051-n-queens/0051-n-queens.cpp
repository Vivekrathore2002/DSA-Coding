class Solution {
public:
    void addSol(vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
        vector<string> sol;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1)
                    row += 'Q';
                else
                    row += '.';
            }
            sol.push_back(row);
        }
        ans.push_back(sol);
    }
    
    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        // Check if there is a queen in the same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }
        
        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }
        
        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1)
                return false;
        }
        
        return true;
    }
    
    void solve(int row, vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
        if (row == n) {
            addSol(board, ans, n);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(row + 1, board, ans, n);
                board[row][col] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
    }
};
