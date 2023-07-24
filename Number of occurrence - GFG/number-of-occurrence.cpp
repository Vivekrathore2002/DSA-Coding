//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int first=-1;
	    int last=-1;
	    int i=0;
	    // Find the first occurrence of x
    while (i < n) {
        if (arr[i] == x) {
            first = i;
            break;
        }
        i++;
    }
    // Find the last occurrence of x
    while (i < n) {
        if (arr[i] == x) {
            last = i;
        }
        i++;
    }
    if(first!=-1)
    return last-first+1;
    else
    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends