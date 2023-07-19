//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// https://www.youtube.com/watch?v=U095bJJtW3w&t=388s
class Solution{
  public:
  int solve(string& a, string& b){
        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        vector<int> currRow(n2+1, 0);
        vector<int> nextRow(n2+1, 0);

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j])
                    ans = 1 + nextRow[j+1];
                else
                {
                    ans = max(nextRow[j], currRow[j+1]);
                }
                currRow[j] = ans;
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int longestPalinSubseq(string A) {
        string revStr = A;
        reverse(revStr.begin(),revStr.end());
        int ans = solve(A,revStr);
        return ans;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends