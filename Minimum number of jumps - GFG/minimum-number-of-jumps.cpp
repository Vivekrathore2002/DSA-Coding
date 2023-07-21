//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
public:
    int minJumps(int arr[], int n) {
        if (n <= 1) return 0; // If the array has one or zero elements, no jumps required.

        int jumps = 0;
        int current = 0;
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + arr[i]);

            if (farthest == i) // If we encounter an element with value 0
                return -1;

            if (i == current) {
                jumps++;
                current = farthest;
            }

            if (current >= n - 1)
                break;
        }
        return jumps;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends