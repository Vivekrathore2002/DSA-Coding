//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// https://www.youtube.com/watch?v=UGY7FMHt-M8
class Solution{
public:
bool solveMem(int index,int arr[],int n,int target,vector<vector<int>> &dp){
    if(index>=n) return 0;
    if(target<0) return 0;
    if(target==0) return 1;
    if(dp[index][target]!=-1) return dp[index][target];
    bool incl = solveMem(index+1,arr,n,target-arr[index],dp);
    bool excl = solveMem(index+1,arr,n,target,dp);
    return dp[index][target] = incl or excl;
}
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total & 1) return 0; //total is odd
        int target = total/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solveMem(0,arr,N,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends