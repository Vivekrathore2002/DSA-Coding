//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// https://www.youtube.com/watch?v=fiPLaxkhdcQ
class Solution
{
    public:
    long long countWays(int n)
    {
        
        // your code here
        long long int m=1000000007;
        vector<long long int> arr(n+5,0);
        arr[1]=1;arr[2]=2;arr[3]=4;
        for(int i=4 ; i<n+1 ; i++){
            arr[i]=(arr[i-1]%m+arr[i-2]%m+arr[i-3]%m)%m;
        }
        return arr[n];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends