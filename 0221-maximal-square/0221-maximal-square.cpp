// https://www.youtube.com/watch?v=nZAyRZC8tko&list=PLLT4EuYB4kIY_DWiiFY_TW3Egm9pmZPuS&index=4&ab_channel=CodewithAlisha
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans=0;
        //Time complexity will be O(n*m){iterating through all the elements once}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    if(matrix[i][j]=='1'){
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(matrix[i][j] =='1'){
                        dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};