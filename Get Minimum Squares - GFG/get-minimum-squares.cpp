//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


// https://www.youtube.com/watch?v=aJTCcyPrPOA&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=11&ab_channel=CodeHelp-byBabbar

//Reccursion approach - 1 (TLE)
// class Solution{
// 	public:
// 	int solve(int n){
// 	    if(n==0) return 0;
// 	    int ans=n;
// 	    for(int i=1;i*i<=n;i++){
// 	        int temp = i*i;
// 	        ans=min(ans,1+solve(n-temp));
// 	    }
// 	    return ans;
// 	}
// 	int MinSquares(int n)
// 	{
// 	    return solve(n);
// 	}
// };


// Approach 2 reccursion+memoization
class Solution{
	public:
	int solve(int n,vector<int> &dp){
	    if(n==0) return 0;
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int ans=n;
	    for(int i=1;i*i<=n;i++){
	        int temp = i*i;
	        ans=min(ans,1+solve(n-temp,dp));
	    }
	    dp[n]=ans;
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,-1);
	    return solve(n,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends