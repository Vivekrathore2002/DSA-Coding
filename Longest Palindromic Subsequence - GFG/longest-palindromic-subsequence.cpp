//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string s1, string s2, int n, int m){
        int t[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else t[i][j]=max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[n][m];
    }
    int longestPalinSubseq(string A) {
        string s2 = A;
        reverse(s2.begin(),s2.end());
        int n=A.length(), m=s2.length();
        return solve(A, s2, n, m);
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