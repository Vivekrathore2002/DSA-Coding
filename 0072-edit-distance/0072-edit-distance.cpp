// https://www.youtube.com/watch?v=8HEjwf28LyE&ab_channel=CodeHelp-byBabbar
class Solution {
public:

    int solve(string& a, string& b, int i, int j){
        // base case
        if(i == a.length())
            return (b.length() - j);

        if(j == b.length())
            return (a.length() - i);

        int ans = 0;

        if(a[i] == b[j])
            return solve(a, b, i+1, j+1);

        else
        {
            // insert
            int insertAns = 1 + solve(a, b, i, j+1);
            
            //delete
            int deleteAns = 1 + solve(a, b, i+1, j);
            
            // update
            int replaceAns = 1 + solve(a, b, i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        
        return ans;
    }

    int solveMem(string& a, string& b, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i == a.length())
            return (b.length() - j);

        if(j == b.length())
            return (a.length() - i);
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if(a[i] == b[j])
            return solveMem(a, b, i+1, j+1, dp);

        else
        {
            // insert
            int insertAns = 1 + solveMem(a, b, i, j+1, dp);
            
            //delete
            int deleteAns = 1 + solveMem(a, b, i+1, j, dp);
            
            // update
            int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        
        return dp[i][j] = ans;
    }

    int solveTab(string& a, string& b){

        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        for(int j=0; j<n2; j++){
            dp[n1][j] =  b.length() - j;
        }

        for(int i=0; i<n1; i++){
            dp[i][n2] =  a.length() - i;
        }

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){

                int ans = 0;

                if(a[i] == b[j])
                    ans = dp[i+1][j+1];

                else
                {
                    // insert
                    int insertAns = 1 + dp[i][j+1];
                    
                    //delete
                    int deleteAns = 1 + dp[i+1][j];
                    
                    // update
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int solveSpaceOP(string& a, string& b){

        int n1 = a.length();
        int n2 = b.length();

        vector<int> curr(n2+1, 0);
        vector<int> next(n2+1, 0);


        for(int j=0; j<n2; j++){
            next[j] =  b.length() - j; // as last row is showed by next
        }

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){

                // Important catch from base case
                curr[b.length()] = a.length() - i;

                int ans = 0;

                if(a[i] == b[j])
                    ans = next[j+1];

                else
                {
                    // insert
                    int insertAns = 1 + curr[j+1];
                    
                    //delete
                    int deleteAns = 1 + next[j];
                    
                    // update
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                
                curr[j] = ans;
            }

            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2) {

        // RECURSION
        // return solve(word1, word2, 0, 0);

        // RECURSION + MEMOIZATION
        /*
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

        return solveMem(word1, word2, 0, 0, dp);
        */

        // TABULATION
        // return solveTab(word1, word2);

        // SPACE OPTIMIZATION
        if(word1.length() == 0)
            return word2.length();

        if(word2.length() == 0)
            return word1.length();
            
        return solveSpaceOP(word1, word2);
    }
};