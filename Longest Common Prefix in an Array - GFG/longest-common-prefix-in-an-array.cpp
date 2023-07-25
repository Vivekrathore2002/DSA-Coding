//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(string arr[], int N) {
        if (N == 0) {
            return "-1"; // Empty input, return "-1" as there is no common prefix.
        }

        string prefix = arr[0]; // Take the first string as the initial prefix.

        for (int i = 1; i < N; i++) {
            int j = 0;
            while (j < prefix.length() && j < arr[i].length()) {
                if (prefix[j] != arr[i][j]) {
                    break; // Found a mismatch, stop comparing and update the prefix.
                }
                j++;
            }
            prefix = prefix.substr(0, j); // Update the prefix with the common characters.
            
            if (prefix.empty()) {
                return "-1"; // If the prefix becomes empty, there is no common prefix.
            }
        }

        return prefix;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends