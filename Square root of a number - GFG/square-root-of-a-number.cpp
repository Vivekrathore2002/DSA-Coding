//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
{
    // Corner case: If the input is 0 or 1, the square root is itself.
    if (x == 0 || x == 1)
        return x;
    long long int s = 0;
    long long int e = x;
    long long int result = -1;
    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        // Check if the square of mid is equal to x.
        if (mid * mid == x) {
            return mid;
        }
        // If the square of mid is greater than x, search in the left half.
        else if (mid * mid > x) {
            e = mid - 1;
        }
        // If the square of mid is less than x, search in the right half.
        else {
            s = mid + 1;
            result = mid; // Store the current mid as the potential answer.
        }
    }
    return result;
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends