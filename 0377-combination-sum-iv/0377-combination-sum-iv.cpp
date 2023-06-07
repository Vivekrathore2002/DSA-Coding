// https://youtube.com/watch?v=Wct0mN2SCRQ&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=11&ab_channel=CodeHelp-byBabbar
//Basic first approach of Simple Reccursion
// class Solution {
// public:
// int solve(vector<int> &nums,int target){
//     //Base case
//     if(target<0) return 0;
//     if(target==0) return 1;
//     int ans =0;
//     for(int i=0;i<nums.size();i++){
//         ans+=solve(nums,target-nums[i]);
//     }
//     return ans;
// }
//     int combinationSum4(vector<int>& nums, int target) {
//         return solve(nums,target);
//     }
// };

//Approach - 2 top down approach or memoization
class Solution {
public:
int solve(vector<int> &nums,int target,vector<int> &dp){
    //Base case
    if(target<0) return 0;
    if(target==0) return 1;
    if(dp[target]!=-1) return dp[target];
    int ans =0;
    for(int i=0;i<nums.size();i++){
        ans+=solve(nums,target-nums[i],dp);
    }
    dp[target]=ans;
    return dp[target];
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};