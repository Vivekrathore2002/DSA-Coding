// https://www.youtube.com/watch?v=ox7fOk3HjlA&ab_channel=CodeHelp-byBabbar

// Approach - 1 Recursive(TLE)
// class Solution {
// public:
//     int numTrees(int n) {
//         if(n<=1) return 1;
//         int ans=0;
//         //Think i as a root node
//         for(int i=1;i<=n;i++){
//             ans+= numTrees(i-1) * numTrees(n-i);
//         }
//         return ans;
//     }
// };

// //Now add dp here 
// class Solution {
// public:
// int solve(int n,vector<int> &dp){
//     if(n<=1) return 1;
//     if(dp[n] != -1) return dp[n];
//         int ans=0;
//         //Think i as a root node
//         for(int i=1;i<=n;i++){
//             ans += solve(i-1,dp) * solve(n-i,dp);
//         }
//         dp[n] = ans;
//         return dp[n];
// }
//     int numTrees(int n) {
//         vector<int> dp(n+1,-1);
//         return solve(n,dp);
//     }
// };


// approach - 3 tabulation
class Solution {
public:
int solve(int n){
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
    int numTrees(int n) {
        return solve(n);
    }
};