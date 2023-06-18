// For reference:https://www.youtube.com/watch?v=TM3vA2s91u8&ab_channel=TechAdorabyNivedita

// //Recursive approach - TLE
// class Solution {
// public:
//     long mod = 1e9+7;
//     int find(int n)
//     {
//         if(n<=1)
//      {
//          return 1;
//      }
//      if(n==2)
//      {
//          return 2;
//      }
//      return (2*find(n-1)%mod + find(n-3)%mod)%mod;
//     }
//     int numTilings(int n) {
//      return find(n);
//     }
// };



// // Approach 1 - Memoization
// class Solution {
// public:
//     long mod = 1e9+7;
//     int find(int n,vector<int>&dp)
//     {
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     dp[n]=(2*find(n-1,dp)%mod + find(n-3,dp)%mod)%mod;
//     return dp[n];
//     }
//     int numTilings(int n) {
//     vector<int>dp(1001,-1);
//     dp[0] =1,dp[1]=1,dp[2]=2;
//      return find(n,dp);
//     }
// };

// Approach 2 - tabulation
class Solution {
public:
    long mod = 1e9+7;
    // int find(int n,vector<int>&dp)
    // {
    // if(dp[n]!=-1)
    // {
    //     return dp[n];
    // }
    // dp[n]=(2*find(n-1,dp)%mod + find(n-3,dp)%mod)%mod;
    // return dp[n];
    // }
    int numTilings(int n) {
    vector<int>dp(1001,-1);
    dp[0] =1,dp[1]=1,dp[2]=2;
     for(int i=3;i<=n;i++)
     {
         dp[i] = (2*dp[i-1]%mod + dp[i-3]%mod)%mod;
     }
     return dp[n];
    }
};