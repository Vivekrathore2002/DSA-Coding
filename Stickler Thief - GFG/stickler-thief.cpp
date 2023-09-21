//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

//from house robber problem leetcode
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int nums[],int n) {
        // int n = nums.size();

        int prev2=0;
        int prev1 = nums[0];
        for (int i = 1; i < n; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;
            int ans = max(incl, excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int FindMaxSum(int nums[], int n)
    {
        int ans = solve(nums,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends